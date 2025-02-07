let location1 = Math.floor(Math.random() * 5);
let location2 = location1 + 1, location3 = location1 + 2;
let guesses = 0;
let guess; 
let hits = 0;
let isSunk = false;
while (!isSunk) {
    guess = prompt("Enter a guess between 0-6");
    if (guess < 0 || guess > 6) {
        alert("Invalid Input");
    }
    else {
        guesses += 1;
        if (guess == location1 || guess == location2 || guess == location3) {
            alert("HIT");
            hits += 1;
            if (hits == 3) {
                isSunk = true;
                alert("You sunk my ship");
            }
        }
        else {
            alert("Miss");
        }
    }
}
alert("Your guesses were" + guesses + " and accuracy was " + 3 / guesses + " .");