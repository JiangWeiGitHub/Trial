class carModel {
  constructor(type) {
    this.type = type
  }

  start() {
    console.log(this.type + ' has started!')
  }

  stop() {
    console.log(this.type + ' has stopped!')
  }

  alarm() {
    console.log(this.type + ' is shouting...')
  }

  run() {
    this.start()
    this.alarm()
    this.stop()
  }
}

let test1 = new carModel('BMW')
test1.run()

let test2 = new carModel('BENZ')
test2.run()