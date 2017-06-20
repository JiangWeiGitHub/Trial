var stack = [1,2,3,4,5,6,7,8,9]
var tmp = []

console.log('>>>>>>>>>>')
console.log('stack: ' + stack)

for(var i = stack.length - 1; i >= 0; i--) {
  tmp.push(stack[i])
}

stack = tmp

console.log('>>>>>>>>>>')
console.log('stack: ' + stack)
