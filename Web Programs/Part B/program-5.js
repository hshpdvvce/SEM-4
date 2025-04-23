// Arrow function using rest operator to calculate the perimeter of a rectangle
const Perimeter = (...sides) => 2 * (sides[0] + sides[1]);

// Using spread operator to pass parameters
const rectangleSpread = [10, 5];
const perimeterSpread = Perimeter(...rectangleSpread);
console.log(`Perimeter (using spread): ${perimeterSpread}`);

// Using rest operator to receive parameters
const perimeterRest = Perimeter(8, 6);
console.log(`Perimeter (using rest): ${perimeterRest}`);