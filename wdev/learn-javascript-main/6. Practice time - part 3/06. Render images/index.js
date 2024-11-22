// Create a function that renders the three team images
// Use a for loop, template strings (``), plus equals (+=)
// .innerHTML to solve the challenge.
const cont = document.getElementById("container")
const imgs = ["images/hip1.jpg", "images/hip2.jpg", "images/hip3.jpg"]
let toRender = ""
function render() {
  for (let i = 0; i < imgs.length; i++) {
    toRender += `
        <img class ='team-img' src = '${imgs[i]}'> `
  }
  cont.innerHTML = toRender
}
render()
