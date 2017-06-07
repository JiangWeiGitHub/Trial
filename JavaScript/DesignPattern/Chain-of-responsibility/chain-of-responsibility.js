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

  sendQuery(entity) {
    console.log('Kid said: ' + entity.getContents() + ' < Level: ' + entity.getLevel() + ' >')
    this.queue.checkQuery(entity)
  }
}

class Dad extends People {
  
  checkQuery(entity) {
    let level = entity.getLevel()
    switch (level) {
      case 'low':
        console.log('Dad said: OK!')
        break
      default:
        console.log('Dad said: I can\'t decide by myself...')
        this.queue.checkQuery(entity)
    }
  }
}

class Grandpa extends People {
 
  checkQuery(entity) {
    let level = entity.getLevel()
    switch (level) {
      case 'low':
        console.log('Grandpa said: OK!')
        break
      case 'middle':
        console.log('Grandpa said: OK!')
        break
      default:
        console.log('Grandpa said: I can\'t decide by myself...')
        this.queue.checkQuery(entity)
    }
  }
}

class Grandma extends People {
 
  checkQuery(entity) {
    let level = entity.getLevel()
    switch (level) {
      case 'low':
        console.log('Grandma said: OK!')
        break
      case 'middle':
        console.log('Grandma said: OK!')
        break
      case 'high':
        console.log('Grandma said: OK!')
        break
      default:
        console.log('Oops!')
    }
  }
}

let kid = new Kid()
let dad = new Dad()
let grandpa = new Grandpa()
let grandma = new Grandma()

let query = new Query()

kid.setNext(dad)
dad.setNext(grandpa)
grandpa.setNext(grandma)

query.setContents('Can I play PS4?')
query.setLevel('high')
kid.sendQuery(query)

console.log('########################################')

query.setContents('Can I go out?')
query.setLevel('low')
kid.sendQuery(query)

console.log('########################################')

query.setContents('Can I have an ice cream?')
query.setLevel('middle')
kid.sendQuery(query)