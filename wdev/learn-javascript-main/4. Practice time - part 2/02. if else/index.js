let age = 20

// less than 6 years old -> free
// 6 to 17 years old     -> child discount
// 18 to 26 years old    -> student discount
// 27 to 66 years old    -> full price
// over 66 years old     -> senior citizen discount

// Create a conditional statement (if/else/else if) that logs out the discount
// the passenger will get based upon the value of the age variable
let discount = ""
if (age < 6) {
  discount = "Free"
} else if (age < 18) {
  discount = "Child discount"
} else if (age < 27) {
  discount = "Student discount"
} else if (age < 67) {
  discount = "No discount"
} else {
  discount = "Senior citizen discount"
}
console.log(discount)
