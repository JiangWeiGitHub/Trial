class Singleton {

  constructor() {
    this.counter = 0
  }

  a() {
    console.log(this.counter ++)
  }

  b() {
    console.log(this.counter ++)
  }
}

let singleton = new Singleton()

export const testAAA = () => singleton.a()
export const testBBB = () => singleton.b()
