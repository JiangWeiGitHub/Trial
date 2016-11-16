function getWeather () {
  return new Promise(function (resolve, reject){
    resolve('What a nice day!')
  })
}

let generator = function* () {
  try {
    let result = yield getWeather()
    console.log(result)
  }
  catch (e) {
    console.log(e);
  }
};

function run (generator) {
  let it = generator()

  function go(result) {

    if (result.done) {
      return result.value
    }

    return result.value.then(function (value) {
      return go(it.next(value))
    }, function (error) {
      return go(it.throw(error))
    })
  }

  go(it.next())
}

run(generator)
