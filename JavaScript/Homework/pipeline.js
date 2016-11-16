const pipeline = (...functionList) => (val => functionList.reduce((former, latter) => latter(former), val))

const plus = a => a + 1
const mult = a => a * 2
const double = a => a * a

console.log(pipeline(plus, mult, double)(5))

// 144
