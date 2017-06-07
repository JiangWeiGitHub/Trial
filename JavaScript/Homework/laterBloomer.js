// class LateBloomer {
  
//   constructor () {
//   	this.petalCount = Math.ceil(Math.random() * 12) + 1
// 	}

// 	declare () {
// 		console.log('I am a beautiful flower with ' +
// 		this.petalCount + ' petals!')
// 	}	

// 	bloom () {
// 		setTimeout(this.declare.bind(this), 1000)
// 	}
// }

// - second way -
// class LateBloomer {
  
//   constructor () {
//   	this.petalCount = Math.ceil(Math.random() * 12) + 1


// 		this.declare = () => {
// 			console.log('I am a beautiful flower with ' +
// 			this.petalCount + ' petals!')
// 		}	

// 		this.bloom  = () => {
// 			console.log(this)
// 			setTimeout(this.declare, 1000)
// 		}

//  	}
// }

// - third way -
function LaterBloomer () {
	this.petalCount = Math.ceil(Math.random() * 12) + 1
}

LaterBloomer.prototype.declare =  function() {
	console.log('I am a beautiful flower with ' + this.petalCount + ' petals!')
}

LaterBloomer.prototype.bloom = function() {
	setTimeout(this.declare.bind(this), 1000)
}

let flower = new LaterBloomer()
flower.bloom()

// - Prototype chain -
console.log('LaterBloomer.__proto__ === Function.prototype: ', LaterBloomer.__proto__ === Function.prototype)

console.log('flower.__proto__ === LaterBloomer.prototype: ', flower.__proto__ === LaterBloomer.prototype)

// - the egg & chicken -
console.log('Object.prototype === Function.__proto__: ', Object.prototype === Function.__proto__)

console.log('Object.prototype === Function.__proto__.__proto__: ', Object.prototype === Function.__proto__.__proto__)

console.log('Object.__proto__ === Function.prototype: ', Object.__proto__ === Function.prototype)

console.log('Function.prototype === Function.__proto__: ', Function.prototype === Function.__proto__)

console.log('Object.prototype === Object.__proto__: ', Object.prototype === Object.__proto__)

console.log('Object instanceof Function: ', Object instanceof Function)

console.log('Function instanceof Object: ', Function instanceof Object)