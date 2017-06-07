let a = function(a){
  let x = a + 10
  return {
    aaa: function(){
      console.log("Result: " + x++)
    }
  }
}

let b = a(30)

b.aaa()
b.aaa()
b.aaa()

