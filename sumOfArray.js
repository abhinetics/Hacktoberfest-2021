// Write function that sum up all number in array.
// Example : 
// [1,2,3] = 1+2+3 => 6
// [-1,2,3] = -1+2+3 => 5
const sumArray = (arr) => {
  return arr.reduce((acc, cur) => acc += cur, 0);
}

module.exports = {
  sumArray
}