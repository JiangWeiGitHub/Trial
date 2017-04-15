class Query {
  setContents(contents) {
    this.contents = contents
  }

  setLevel(name) {
    this.level = name
  }

  getContents() {
    return this.contents
  }

  getLevel() {
    return this.level
  }
}

class People {
  constructor() {
    this.queue = null
  }

  setNext(person) {
    this.queue = person
  }

  checkQuery() {}

  sendQuery(entity) {
    this.queue.checkQuery(entity)
  }
}

class Kid extends People {
  constructor() {
    super()
    this.queue = null
  }

  sendQuery(entity) {
    console.log('Kid said: ' + entity.getContents() )
    console.log('Level: ' + entity.getLevel())
    this.queue.checkQuery(entity)
  }
}

class Dad extends People {
  constructor() {
    super()
    this.queue = null
  }
  
  checkQuery(entity) {
    let level = entity.getLevel()
    switch (level) {
      case 'low':
        console.log('Dad said: OK!')
        break
      case 'high':
        console.log('Dad said: I can not decide by myself.')
        this.queue.checkQuery(entity)
        break
      default:
        console.log('Oops!')
    }
  }
}

class Grandpa extends People {
  constructor() {
    super()
    this.queue = null
  }
  
  checkQuery(entity) {
    let level = entity.getLevel()
    switch (level) {
      case 'low':
        console.log('Grandpa said: OK!')
        break
      case 'high':
        console.log('Grandpa said: OK!')
    }
  }
}

let kid = new Kid()
let dad = new Dad()
let grandpa = new Grandpa()

let query = new Query()

kid.setNext(dad)
dad.setNext(grandpa)

query.setContents('Can I play PS4?')
query.setLevel('high')
kid.sendQuery(query)

console.log('########################################')

query.setContents('Can I go out?')
query.setLevel('low')
kid.sendQuery(query)