// http://baike.baidu.com/item/%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%B7%E7%AE%97%E6%B3%95

const Euclidean = (small, remainder) => {
  remainder ?
    (small > remainder ? Euclidean(remainder, small % remainder) : Euclidean(small, remainder % small))
            :
    (console.log('The greatest common divisor is: ' + small))
}

const a = 99
const b = 27

a > b ?
  Euclidean(b, a % b)
      :
  Euclidean(a, b % a)
