var a = 10
var b = 99

console.log('>>>>>>>>>')
console.log('a: ' + a)
console.log('b: ' + b)

a += b
b = a - b
a -= b

console.log('<<<<<<<<<')
console.log('a: ' + a)
console.log('b: ' + b)

a ^= b
b ^= a
a ^= b

console.log('>>>>>>>>>')
console.log('a: ' + a)
console.log('b: ' + b)

