class Order {
  order() {}
}

class Run extends Order {
  constructor(name) {
    super()
    this.name = name
  }

  order() {
    this.name.run()
  }
}

class Stop extends Order {
  constructor(name) {
    super()
    this.name = name
  }

  order() {
    this.name.stop()
  }
}

class Exercise {
  run() {
    console.log('Run Run Run!')
  }

  stop() {
    console.log('Stop!')
  }
}

class General {
  order(name) {
    name.order()
  }
}

let exercise = new Exercise()
let run = new Run(exercise)
let stop = new Stop(exercise)
let general = new General()
general.order(run)
general.order(stop)