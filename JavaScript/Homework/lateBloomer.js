class LateBloomer {
  
  constructor () {
  	this.petalCount = Math.ceil(Math.random() * 12) + 1
	}

	declare () {
		console.log('I am a beautiful flower with ' +
		this.petalCount + ' petals!')
	}	

	bloom () {
		setTimeout(this.declare.bind(this), 1000)
	}
}

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


let flower = new LateBloomer()
flower.bloom()
