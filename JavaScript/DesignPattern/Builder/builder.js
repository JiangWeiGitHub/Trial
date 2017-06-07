class Car {
  constructor() {
    this.type = null
    this.color = null
    this.price = null
  }

  infor() {
    console.log(this.type)
    console.log(this.color)
    console.log(this.price)
  }

  setColor(color) {
    this.color = color
  }

  setPrice(price) {
    this.price = price
  }
}

class BMW extends Car {
  constructor() {
    super()
    this.type = 'bmw'
  }
}

class BENZ extends Car {
  constructor() {
    super()
    this.type = 'benz'
  }

  setPrice(price) {
    this.price = price * 1.6
  }
}

class Builder {
  setType(type) {
    switch(type) {
      case 'BMW':
        this.entity = new BMW()
        break
      case 'BENZ':
        this.entity = new BENZ()
        break
      default:
        console.log('Unrecognized Type')
    }
  }

  setColor(color) {
    this.color = color
  }

  setPrice(price) {
    this.price = price
  }

  build() {
    this.entity.setColor(this.color)
    this.entity.setPrice(this.price)

    return this.entity
  }
}

let builder = new Builder()

builder.setType('BMW')
builder.setColor('red')
builder.setPrice(50000)
let bmw1 = builder.build()

builder.setType('BMW')
builder.setColor('black')
builder.setPrice(80000)
let bmw2 = builder.build()

builder.setType('BENZ')
builder.setColor('silver')
builder.setPrice(46000)
let benz1 = builder.build()

bmw1.infor()
console.log('######################')
bmw2.infor()
console.log('######################')
benz1.infor()