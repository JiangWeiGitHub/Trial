class Creature {

  // constructor() {
  //   this.sentence = null
  // }

  shout() {}

  teach() {}

  // addPower(newPower) {
  //   this.shout = newPower.shout
  // }
}

class Someone extends Creature {
  constructor(type) {
    super()
    this.sentence = null
    this.shout = type.shout
  }

  teach(sentence) {
    this.sentence = sentence
  }

  change(type) {
    this.shout = type.shout
  }
}

class CatSound extends Creature {
  shout() {
    console.log(this.sentence + ': Miao')
  }
}

class DogSound extends Creature {
  shout() {
    console.log(this.sentence + ': Wang')
  }
}

class CockSound extends Creature {
  shout() {
    console.log(this.sentence + ': OOO')
  }
}

let kitty = new Someone(new CatSound())
kitty.teach('Cat')
kitty.shout()
kitty.change(new DogSound())
kitty.teach('Dog')
kitty.shout()
kitty.teach('Cock')
kitty.change(new CockSound())
kitty.shout()