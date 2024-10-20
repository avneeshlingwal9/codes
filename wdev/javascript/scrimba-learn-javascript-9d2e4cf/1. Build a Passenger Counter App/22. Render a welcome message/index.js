// Grab the welcome-el paragraph and store it in a variable called welcomeEl
let welcomeEl = document.getElementById("welcome-el") 

// Create two variables (name & greeting) that contains your name
let nam = "Slim Shady"
let gretting = "Welcome back "
// and the greeting we want to render on the page
welcomeEl.innerText = gretting+ nam

// Render the welcome message using welcomeEl.innerText
welcomeEl.innerText= welcomeEl.innerText+" by"
