class Mom {
  constructor() {
    this.mood = 'normal'
    // this.mediator = mediator
  }

  cook() {
    console.log('Mom is cooking...')
    console.log('Done!')
  }

  buy(contents) {
    console.log('Mom bought a ' + contents + '!')
  }

  clean(mediator) {
    console.log('Mom is cleaning...')
    mediator.calling('cleanUpGarbage')
    console.log('Done!')
  }
}

class Dad {
  constructor() {
    // this.mediator = mediator
  }

  payBill(number) {
    console.log('Spent ' + number + ' Yuan!')
  }

  cleanUpGarbage() {
    console.log('Thanks Dad!')
    console.log('The trash can is clean!')
  }

  wantSomething(mediator) {
    console.log('Dad wants a T-shirt!')
    mediator.calling('buy', 'T-shirt')
  }
}

class MediatorSkeleton {
  constructor() {
    this.mom = new Mom()
    this.dad = new Dad()
  }

  calling(type, contents) {}
}

class Mediator extends MediatorSkeleton {
  constructor() {
    super()
  }

  calling(type, contents) {
    switch(type) {
      case 'cleanUpGarbage':
        this.dad.cleanUpGarbage()
        break
      case 'buy':
        this.mom.buy(contents)
        break
      default:
        console.log('Nothing happens!')
    }
  }
}

let mom = new Mom()
let dad = new Dad()
let mediator = new Mediator()

mom.cook()
mom.buy('Book')
mom.clean(mediator)

dad.payBill(100)
dad.wantSomething(mediator)