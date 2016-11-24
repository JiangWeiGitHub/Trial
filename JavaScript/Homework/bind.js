//bind

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
