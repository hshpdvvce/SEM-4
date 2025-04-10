// Create a class by the name rectangle with 2 attributes length and breadth. 
// Include a parameterized constructor to assign values to data members and a function to calculate area of the rectangle. 
// Demonstrate creation of object of class rectangle and display its area.
// Input: length=5, breadth=6
// Output: Area=30

class Rectangle {
  constructor(length, breadth) {
    this.length = length;
    this.breadth = breadth;
  }

  calculateArea() {
    return this.length * this.breadth;
  }
}

// Creating an object of the Rectangle class
let myRectangle = new Rectangle(5, 10);

// Displaying the area of the rectangle
console.log("Length:", myRectangle.length);
console.log("Breadth:", myRectangle.breadth);
console.log("Area:", myRectangle.calculateArea());