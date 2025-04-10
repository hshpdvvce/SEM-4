// Develop a JavaScript program to demonstrate the usage of optional and default parameters in a function.

// Optional parameters
function disp(a, b, c) {
  c = c || 10; // Assign default value to 'c' if not provided
  console.log(a + b + c);
}
disp(10, 10); // Output: 30

// Default parameters
function hello(a, b = 1) {
  console.log(a + b);
}
hello(10); // Output: 11