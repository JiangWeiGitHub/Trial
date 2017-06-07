const NUMBER = 5

function singleton() {
  let counter = 0
  return function (number) {
    if(counter) {
      if(counter < NUMBER) {
        counter = counter + 1
        console.log("I'm " + number + " !")
      }
      else {
        console.log("I'm " + NUMBER + " !")
      }
    }
    else {
      counter = 1
      console.log("I'm " + number + " !")
    }

    return counter
  }
}

let test = singleton()
console.log(test(145))
console.log(test(45))
console.log(test(3254))
console.log(test(44))
console.log(test(5452))
console.log(test(668))
console.log(test(78))
console.log(test(38))
console.log(test(942))