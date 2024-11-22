let firstCard = 10
let secondCard = 11
let sum = firstCard + secondCard

// Write the conditional according to these rules:

// if less than or equal to 20 ->
// else if exactly 21 ->
// else ->

if (sum <= 20) {
  console.log("Do you want to draw a new card? 🙂")
} else if (sum === 21) {
  console.log("Wohoo! You've got Blackjack! 🥳")
} else {
  console.log("You're out of the game! 😭")
}