// Develop a JavaScript program that accepts length and breadth of a rectangle as parameters of an arrow function. 
// Call the function using spread and rest operators and alert the user with the perimeter of the rectangle.

// Arrow function to calculate the perimeter of a rectangle
const Perimeter = (length, breadth) => 2 * (length + breadth);

// Using spread operator to pass parameters
const rectangleSpread = [10, 5];
const perimeterSpread = Perimeter(...rectangleSpread);
console.log(`Perimeter (using spread): ${perimeterSpread}`);

// Using rest operator to pass parameters
const rectangleRest = [8, 6];
const perimeterRest = Perimeter(...rectangleRest);
console.log(`Perimeter (using rest): ${perimeterRest}`);