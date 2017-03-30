function a(tmp1) {
  return function b(tmp2) {
    return function c(tmp3) {
      return tmp1 + tmp2 + tmp3
    }
  }
}

console.log(a(1)(2)(3))
