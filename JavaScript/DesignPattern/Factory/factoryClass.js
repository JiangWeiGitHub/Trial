class Factory {
  constructor(type) {
		this.type = type
	}

	createSomething() {
		if(this.type  === 'aaa') {
			return new AAA().createSomething()
		}
		else if(this.type  === 'bbb') {
			return new BBB().createSomething()
		}
		else if(this.type  === 'ccc') {
			return new CCC().createSomething()
		}
	}
}

class AAA extends Factory {
	createSomething() {
		let tmp = Date()
		console.log("I'm aaa! Today is: " + tmp)
	}
}

class BBB extends Factory {
	createSomething() {
		console.log("I'm bbb! " + "1 + 2 = " + `${1+2}`)
	}
}

class CCC extends Factory {
	createSomething() {
		console.log("I'm ccc! "	+	`${[1,2,3,4,5,6,7,8,9].reduce(function(a, b) { return a + b }, 0)}`)
	}
}

let aaa = new Factory('aaa').createSomething()
let bbb = new Factory('bbb').createSomething()
let ccc = new Factory('ccc').createSomething()
