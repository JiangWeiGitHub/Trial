let numbers = [1,8545,9,5546,545,454,656,56,56,356,8,465,34,4,45,48,45,548,54]

let final = numbers;

numbers.forEach(()=>{

  final = final.map((current, index, array) => {

    if(current > array[index + 1]){
      let tmp = array[index + 1]
      array[index + 1] = current
      current = tmp

      return tmp
    }

    return current

  });
})

console.log(final)