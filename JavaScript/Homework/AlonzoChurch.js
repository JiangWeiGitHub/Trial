'use strict';

// define number 0:
var zero = function (f) {
    return function (x) {
        return x;
    }
};

// define number 1:
var one = function (f) {
    return function (x) {
        return f(x);
    }
};

// define add method:
function add(n, m) {
    return function (f) {
        return function (x) {
            return m(f)(n(f)(x));
        }
    }
}

// 2 = 1 + 1:
var two = add(one, one);

// 3 = 1 + 2:
var three = add(one, two);

// 5 = 2 + 3:
var five = add(two, three);

// test 'three' & 'five':
(three(function () {
    console.log('print 3 times');
}))();

(five(function () {
    console.log('print 5 times');
}))();
