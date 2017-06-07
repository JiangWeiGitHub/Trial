// part 1
global.x = 9

const test = {
  x: 81,
  getX: function() { return this.x }
}

console.log(test.getX())

let retrieveX = test.getX
console.log(retrieveX())

let boundGetX = retrieveX.bind(test)
console.log(boundGetX())

// part 2

/* return 37 */
// var root = { prop: 37 };

// function getRoot() {
//   return this.prop;
// }

// root.getAnother = { get: (getRoot).bind(root), prop: 42}

// console.log(root.getAnother.get())


/* return 42 */
var root = { prop: 37 };

function getRoot() {
  return this.prop;
}

root.getAnother = { get: getRoot, prop: 42}

console.log(root.getAnother.get())
