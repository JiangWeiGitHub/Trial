class People {
  echo() {}
}

class Star extends People {
  constructor(name) {
    super()
    this.name = name
  }

  echo() {
    console.log('Real Name: ' + this.name)
  }
}

class Nickname extends People {
  constructor(people) {
    super()
    this.people = people
  }

  addNickname(nickname) {
    this.people.nickname = nickname
  }

  echo() {    
    console.log('Nick name: ' + this.people.nickname)
    this.people.echo()
  }
}

let star = new Star('Tommy')

star = new Nickname(star)
star.addNickname('Tom')

star.echo()