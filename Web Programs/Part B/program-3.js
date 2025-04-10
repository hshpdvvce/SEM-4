// Develop a JavaScript program to demonstrate the working of callback and async functions.

// Callback Example
hello(goodbye);

function hello(callback) {
  console.log("hello");
  callback();
}

function goodbye() {
  console.log("bye");
}

// Async Example
console.log("start");

setTimeout(() => {
  console.log("hey");
}, 2000);

console.log("end");