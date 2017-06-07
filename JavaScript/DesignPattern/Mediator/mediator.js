class Mom {
  constructor() {
    this.mood = 'normal'
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

  happy() {
    this.mood = 'happy'
  }

  normal() {
    this.mood = 'normal'
  }
}

class Dad {

  payBill(number) {
    console.log('Dad spent ' + number + ' Yuan!')
  }

  cleanUpGarbage() {
    console.log('Thanks Dad!')
    console.log('The trash can is clean!')
  }

  wantSomething(mediator) {
    console.log('Dad wants a T-shirt!')
    mediator.calling('buy', 'T-shirt')
  }

  beg(mediator) {
    console.log('Smile please!')
    mediator.calling('momMood', 'happy')
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
      case 'momMood':
        this.mom.happy()
        break
      case 'cleanUpGarbage':
        this.dad.cleanUpGarbage()
        break
      case 'buy':
        if(this.mom.mood === 'happy') {
          this.mom.buy(contents)
        }
        else {
          console.log('No way!')
        }      
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
dad.beg(mediator)
dad.wantSomething(mediator)