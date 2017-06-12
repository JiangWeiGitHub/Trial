let numbers = [1,8545,9,5546,545,454,656,56,56,356,8,465,34,4,45,48,45,548,54]

let firstArr = []
firstArr.push(numbers[0])

let secondArr = numbers.slice(1)

for(let i = 0; i < secondArr.length; i ++){

  for(let j = firstArr.length - 1; j >= 0; j --){

    if(firstArr[j] < secondArr[i]){
      firstArr.push(secondArr[j])

      break
    }

    if(firstArr[j] > secondArr[i] && (firstArr[j - 1] <= secondArr[i] || firstArr[j - 1] === undefined)){

      let tmp = firstArr.length
      while(tmp != j){
        firstArr[tmp] = firstArr[tmp - 1]
        tmp--
      }

      firstArr[j] = secondArr[i]

      break
    }
    else {
      continue
    }

  }
}

console.log(firstArr)