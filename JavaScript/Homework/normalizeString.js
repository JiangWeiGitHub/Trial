'use strict';

function normalize(arr) {
  let lowerStringArray = arr.map(function (string) {
    return string.toLowerCase()
  })

  let newStringArray = lowerStringArray.map(function (string){
    let header = string[0].toUpperCase()
    let body = string.substring(1)
    return header + body
  })

  return newStringArray;
}

// test:
if (normalize(['adam', 'LISA', 'barT']).toString() === ['Adam', 'Lisa', 'Bart'].toString()) {
    console.log('Success!');
}
else {
    console.log('Failed!');
}
