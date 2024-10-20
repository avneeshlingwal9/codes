// grab the count-el element, store it in a countEl variable
let count = 0;
let change = document.getElementById("count-el");

function increment() {
  count = count + 1;
  change.innerText = count;
  // set countEl's innerText to the count
}
