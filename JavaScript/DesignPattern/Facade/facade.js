class Add {
  constructor(number) {
    this.number = number
  }

  add() {
    return this.number++
  }
}

class Echo {
  constructor(contents) {
    this.contents = contents
  }

  echo() {
    console.log('" ' + this.contents + ' "')
  }
}

class Facade {
  constructor(param) {
    this.number = param.number + 15
    this.contents = param.contents
  }

  run() {
    let add = new Add(this.number)
    let echo = new Echo(this.contents)
    console.log(add.add())
    echo.echo()
  }
}

const param = {
  number: 10,
  contents: 'Hello World'
}

let facade = new Facade(param)
facade.run()