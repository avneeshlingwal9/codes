let hands = ["rock", "paper", "scissor"]

// Create a function that returns a random item from the array


function rando() {
  let randnum = Math.floor(Math.random() * 3)
  return hands[randnum]
}
console.log(rando())