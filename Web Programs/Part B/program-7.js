// Create a class by the name box with parameters length, breadth, and height. 
// Create a class boxweight that extends box and include a new parameter weight. 
// Create another class by the name boxcost that extends boxweight and has a parameter by the name shipmentcost. 
// Include constructors in all the classes. Create an object of boxcost and display values of all parameters 
// that represent multilevel inheritance.

class Box {
  constructor(length, breadth, height) {
    this.length = length;
    this.breadth = breadth;
    this.height = height;
  }
}

class BoxWeight extends Box {
  constructor(length, breadth, height, weight) {
    super(length, breadth, height);
    this.weight = weight;
  }
}

class BoxCost extends BoxWeight {
  constructor(length, breadth, height, weight, shipmentCost) {
    super(length, breadth, height, weight);
    this.shipmentCost = shipmentCost;
  }
}

const myBoxCost = new BoxCost(10, 5, 3, 2, 20);
console.log("Length:", myBoxCost.length);
console.log("Breadth:", myBoxCost.breadth);
console.log("Height:", myBoxCost.height);
console.log("Weight:", myBoxCost.weight);
console.log("Shipment Cost:", myBoxCost.shipmentCost);