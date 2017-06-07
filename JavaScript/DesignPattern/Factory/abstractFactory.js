class Nvwa {
  createMan() {}
  createWoman() {}
}

class Man extends Nvwa {
  createMan(color) {
    if(color === 'black') {
      return new BlackMan()
    }
    if(color === 'white') {
      return new WhiteMan()
    }
    if(color === 'yellow') {
      return new YellowMan()
    }
  }
}

class Woman extends Nvwa {
  createWoman(color) {
    if(color === 'black') {
      return new BlackWoman()
    }
    else if(color === 'white') {
      return new WhiteWoman()
    }
    else if(color === 'yellow') {
      return new YellowWoman()
    }
  }
}

class WomanStyle {
  sayHello() {}
}

class BlackWoman extends WomanStyle {
  sayHello() {
    console.log('I am a black woman!')
  }
}

class WhiteWoman extends WomanStyle {
  sayHello() {
    console.log('I am a white woman!')
  }
}

class YellowWoman extends WomanStyle {
  sayHello() {
    console.log('I am a yellow woman!')
  }
}

class ManStyle {
  sayHello() {}
}

class BlackMan extends ManStyle {
  sayHello() {
    console.log('I am a black man!')
  }
}

class WhiteMan extends ManStyle {
  sayHello() {
    console.log('I am a white man!')
  }
}

class YellowMan extends ManStyle {
  sayHello() {
    console.log('I am a yellow man!')
  }
}

let test1 = new Woman().createWoman('black').sayHello()
let test2 = new Woman().createWoman('white').sayHello()
let test3 = new Woman().createWoman('yellow').sayHello()
let test4 = new Man().createMan('black').sayHello()
let test5 = new Man().createMan('white').sayHello()
let test6 = new Man().createMan('yellow').sayHello()