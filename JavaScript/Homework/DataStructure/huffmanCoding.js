function bubbleSort(arr) {
  var len = arr.length
  for (var i = 0; i < len; i++) {
    for (var j = 0; j < len - 1 - i; j++) {
      if (arr[j] > arr[j+1]) {
        var temp = arr[j+1]
        arr[j+1] = arr[j]
        arr[j] = temp
      }
    }
  }

  return arr
}

function getProbability(inputStr) {
  let tmp = new Map()
  for(let counter = 0; counter < inputStr.length; counter ++) {
    if(tmp.has(inputStr[counter]) === true) {
      tmp.set(inputStr[counter], tmp.get(inputStr[counter]) + 1)
    }
    else {
      tmp.set(inputStr[counter], 1)
    }
  }

  let result = new Map()

  let tmpArr = new Array()

  tmp.forEach((value, key) => {
    result.set(key, Math.round((value / inputStr.length) * 100) / 100)

    tmpArr.push(result.get(key))
  })

  let resultArr = bubbleSort(tmpArr)

  result.set('serial', resultArr)

  return result
}

let testStr = 'jlajsldljiiijijewsdjlsdfj'
let result = getProbability(testStr)
console.log('Test String: ' + testStr)
console.log(result)
