let toChange = document.getElementById("count-el");
let count = 0;
function increment() {
  count++;
  toChange.innerText = count;
}
