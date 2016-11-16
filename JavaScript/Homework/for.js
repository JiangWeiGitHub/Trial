
// for ... in ...
var a = ['A', 'B', 'C'];
a.name = 'Hello';

for (var x in a)
{
    console.log(x); // '0', '1', '2', 'name'
}

// for ... of ...
var a = ['A', 'B', 'C'];
a.name = 'Hello';

for (var x of a)
{
    console.log(x); // 'A', 'B', 'C'
}
