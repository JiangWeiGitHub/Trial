class Fruit {
  constructor() {
    this.child = []
  }

  getFruit(name) {
    for(let counter in this.child) {
      if(this.child[counter].getName() === name) {
        return this.child[counter]
      }
    }

    this.child[this.child.length ? this.child.length : 0] = new FruitCreator(name)
  }

  printCurrentTypes() {
    console.log('Number of instances made: ' + this.child.length)
    for(let number in this.child) {
      console.log(this.child[number].getName())
    }
  }
}

class FruitCreator {
  constructor(name) {
    this.name = name
  }

  getName() {
    return this.name
  }
}

let fruit = new Fruit()

fruit.getFruit('Apple')
fruit.printCurrentTypes()
console.log('#################################')
fruit.getFruit('Apple')
fruit.printCurrentTypes()
console.log('#################################')
fruit.getFruit('Orange')
fruit.printCurrentTypes()
console.log('#################################')
fruit.getFruit('Apple')
fruit.printCurrentTypes()
console.log('#################################')
fruit.getFruit('Apple')
fruit.printCurrentTypes()
console.log('#################################')
fruit.getFruit('Banana')
fruit.printCurrentTypes()