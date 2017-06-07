class TowelVendor {
  printModel() {}
}

class TowelSeller extends TowelVendor {
  constructor(model) {
    super()
    this.model = model
  }

  printModel() {
    console.log('Model: ' + this.model)
    console.log(Date())
  }
}

class TowelProxy extends TowelVendor {
  constructor(model) {
    super()
    if(model === 'happy') {
      this.model = new TowelSeller('happy')
    }
    else {
      this.model = null
    }
  }

  printModel() {
    if(this.model) {
      this.model.printModel()
    }
    else {
      console.log('No this model!')
    }
  }
}

let test1 = new TowelProxy('dfgd')
test1.printModel()

let test2 = new TowelProxy('happy')
test2.printModel()