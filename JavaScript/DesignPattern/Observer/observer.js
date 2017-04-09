class Observer {
  constructor() {
    this.list = []
  }

  add(name) {
    this.list.push(name)
  }

  update(contents) {}
}

class Boss extends Observer {
  constructor() {
    super()
  }

  update(contents) {
    this.list.forEach((name) => {
      name.get(contents)
    })
  }
}

class Employee {
  constructor(name) {
    this.name = name
  }

  get(contents) {
    console.log(this.name + ': ' + contents)
  }
}

let boss = new Boss()
let lucy = new Employee('lucy')
let lily = new Employee('lily')
let tom = new Employee('tom')

boss.add(lucy)
boss.add(lily)
boss.add(tom)

boss.update('Lunch time!')