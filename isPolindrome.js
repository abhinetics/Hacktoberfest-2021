// Write function that checks if a given string (case insensitive) is a palindrome.
// example :
// ABA => true
// ABC => false

const isPolindrome = (words) => {
  return words.split("").reverse().join("").toLowerCase() === words.toLowerCase()
  ? true
  : false;
}

module.exports = {
  isPolindrome
}