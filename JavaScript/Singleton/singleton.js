let singleton = ( value ) => {
  let result
  return () => {
    if(result) return ++result
    return result = value
  }
}

let test = singleton(3)

console.log(test())
console.log(test())
console.log(test())
console.log(test())
console.log(test())
