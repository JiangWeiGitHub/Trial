function factory() {
  this.createEmployee = (type) => {
    let employee

    if (type === "fulltime") {
      employee = new fullTime()
    }
    else if (type === "parttime"){
      employee = new partTime()
    }

    employee.type = type;

    return employee
  }
}

function fullTime() {
  console.log('Full Time')
}

function partTime() {
  console.log('Part Time')
}

let test = new factory()
test.createEmployee('fulltime')
test.createEmployee('parttime')
