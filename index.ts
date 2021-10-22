import "reflect-metadata";
import {createConnection} from "typeorm";
import express, { Request, Response } from 'express'
import { validate } from "class-validator";

import {User} from "./entity/User";
import { Post } from "./entity/Post";

const app = express()
app.use(express.json())

//CREATE
app.post('/users', async(req: Request, res: Response) => {
    const { name, email, role} = req.body // getting the data from the request body
    try {
        const user = User.create({ name, email, role}) 

        const errors = await validate(user)
        if (errors.length > 0) {
            return res.json(errors)
        }
        await user.save()
        // return res.json(user)
        return res.status(201).json(user) //having a status 201 cause user was created
    }
    catch(err){
        console.log(err)
        // return res.status(500).json(err) better for production not giving the actual error
        return res.status(500).json({error : "Something went wrong"})
    }
})
//READ
app.get('/users', async(_: Request, res: Response) => {
    try {
        const users = await User.find({relations: ['posts']})
        return res.json(users)
    }
    catch(err){
        console.log(err)
        return res.status(500).json(err)
    }
})
//UPDATE
app.put('/users/:uuid', async(req: Request, res: Response) => {
    const uuid = req.params.uuid
    const { name, email, role} = req.body
    try {
        const user = await User.findOneOrFail({uuid})
        user.name = name || user.name // || for if giving empty value or old value sets the old
        user.email = email || user.email
        user.role = role || user.role
        
        await user.save()
        return res.json(user)
    }
    catch(err){
        console.log(err)
        return res.status(500).json({error : "Something went wrong"})
    }
})
//DELETE
app.delete('/users/:uuid', async(req: Request, res: Response) => {
    const uuid = req.params.uuid
    try {
        const user = await User.findOneOrFail({uuid})
        
        await user.remove()
        return res.json({message: "User deleted!"})
    }
    catch(err){
        console.log(err)
        return res.status(500).json({error : "Something went wrong"})
    }
})
//FIND
app.get('/users/:uuid', async(req: Request, res: Response) => {
    const uuid = req.params.uuid
    try {
        const user = await User.findOneOrFail({uuid})
        
        return res.json(user)
    }
    catch(err){
        console.log(err)
        return res.status(404).json({user : "User not found"})
    }
})

//CREATE A POST
app.post('/posts',async(req: Request,res: Response) => {
    const { userUuid, title, body } = req.body
    try{
        const user = await User.findOneOrFail({ uuid: userUuid })
        // const post = new Post({title, body, user}) using the constructor, other way
        const post = Post.create({ title, body, user })
        await post.save()

        return res.json(post)
    }
    catch(err){
        console.log(err)
        return res.status(500).json({error : "Something went wrong"})
    }
})
//READ POSTS
app.get('/posts',async(req: Request,res: Response) => {
    try{
        const posts = await Post.find({relations: ['user']})

        return res.json(posts)
    }
    catch(err){
        console.log(err)
        return res.status(500).json({error : "Something went wrong"})
    }
})

createConnection()
  .then(async () => {
    app.listen(5000, () => console.log('Server up at http://localhost:5000'))
  })
  .catch((error) => console.log(error))
