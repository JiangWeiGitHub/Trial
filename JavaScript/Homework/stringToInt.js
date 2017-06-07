'use strict';

function string2int(s) {
  let charArray = [];
  for(let i = 0; i < s.length; i++)
  {
    charArray.push(s[i])
  }

  let intArray = charArray.map(function(tmp){return tmp - '\x30'})

  return intArray.reduce(function(x,y){return x * 10 + y})
}

// test:
if (string2int('0') === 0 && string2int('12345') === 12345 && string2int('12300') === 12300) {
  if (string2int.toString().indexOf('parseInt') !== -1) {
    console.log('Do not use parseInt()!');
  } else if (string2int.toString().indexOf('Number') !== -1) {
    console.log('Do not user Number()!');
  } else {
    console.log('Success!');
  }
}
else {
  console.log('Failed!');
}
