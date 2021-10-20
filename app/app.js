const express = require('express');
const morgan = require('morgan')
const mongoose = require('mongoose')
const blogRoutes = require('./routes/blogRoutes')
const axios = require('axios');
//express app
const DEFAULT_EXPIRATION = 3600
const app = express();

const redis = require('redis')
const redisClient = redis.createClient() 



//redis check ,testing with Postman on http://localhost:3000/photos?albumId=2 e.g.
app.get("/photos", async( req, res) => {
  const albumId = req.query.albumId
  // const photos = await getOrSetCache(`photos?albumId=${albumId}`,async () => {
    // const { data } = await axios.get(
    //   "https://jsonplaceholder.typicode.com/photos",
    //   { params: { albumId} }
    //   )
    // return data }) 
    // res.json(photos)
  // redisClient.get('photos',async(error,photos) => { simpler way just the photos
    redisClient.get(`photos?albumId=${albumId}`,async(error,photos) => {
    if (error) console.log(error);
    if (photos != null ){
      console.log("Cache Hit")
      return res.json(JSON.parse(photos))
    }else {
      console.log("Cache Miss")
      const { data } = await axios.get(
        "https://jsonplaceholder.typicode.com/photos",
        { params: { albumId} }
        )
      // redisClient.setex('photos', DEFAULT_EXPIRATION, JSON.stringify(data))
      redisClient.setex(`photos?albumId=${albumId}`, DEFAULT_EXPIRATION, JSON.stringify(data))
      res.json(data)
    }
  })
})


app.get("/photos/:id", async(req,res)=>{
    const photo = await getOrSetCache(`photos:${req.params.id}`,async () => {
      const { data } = await axios.get(
        `https://jsonplaceholder.typicode.com/photos/${req.params.id}`
      )
    return data 
  })
  res.json(photo)
})

function getOrSetCache(key, cb){
  return new Promise((resolve, reject) => {
    redisClient.get(key, async (error, data) =>{
      if (error) return reject(error)
      if (data != null) return resolve(JSON.parse(data))
      const freshData = await cb()
      redisClient.setex(key, DEFAULT_EXPIRATION, JSON.stringify(freshData))
      resolve(freshData)
    })
  })
}

//connect to mongoDB
//where username - password are your own username-password to mongoDB
const dbURI = 'mongodb+srv://userName:userPassword@cluster0.vqumt.mongodb.net/node-tuts?retryWrites=true&w=majority'
mongoose.connect(dbURI, { useNewUrlParser: true, useUnifiedTopology: true})
  .then((result) => {
      console.log("Successfuly connected to db")
      //listen for requests
      app.listen(3000); 
  })
  .catch((err) => console.log(err));



//register view engine
app.set('view engine', 'ejs')


//middleware and static files
app.use(express.static('public')); // making the folder public accesible to everywhere
app.use(express.urlencoded({ extended: true }));//for accepting form data
app.use(morgan('dev')); //using ready middleware 'morgan' to preview get

app.get('/', (req, res) => {
  res.redirect('/blogs')
  //res.send('<p>home page</p>');
  // const blogs = [
  //   {title: 'Yoshi finds eggs', snippet: 'Lorem ipsum dolor sit amet consectetur'},
  //   {title: 'Mario finds stars', snippet: 'Lorem ipsum dolor sit amet consectetur'},
  //   {title: 'How to defeat bowser', snippet: 'Lorem ipsum dolor sit amet consectetur'},
  // ];
  // res.render('index', { title: 'Home', blogs });
})

app.get('/about', (req, res) => {
  res.render('about', { title: 'About' });
})

app.use(blogRoutes)
//we could use app.use('/blogs', blogRoutes) --> then to blogRoutes we could
//delete the /blogs from every router.sth('/')

//404page -- works as a catchAll- must be at the bottom
app.use((req, res) => {
  res.status(404).render('404', { title: '404' })
})
