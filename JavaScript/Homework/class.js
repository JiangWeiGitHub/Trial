'use strict';

class Animal {
  constructor(name) {
    this.name = name;
  }
}

class Cat extends Animal {
  constructor(name){
    super(name)
  }

  say(){
    return 'Hello, ' + this.name + '!'
  }
}

// test:
var kitty = new Cat('Kitty');
var doraemon = new Cat('Bear');
if ((new Cat('x') instanceof Animal)
     && kitty && kitty.name === 'Kitty'
     && kitty.say && typeof kitty.say === 'function'
     && kitty.say() === 'Hello, Kitty!'
     && kitty.say === doraemon.say)
{
  console.log('Success!');
}
else
{
  console.log('Failed!');
}
