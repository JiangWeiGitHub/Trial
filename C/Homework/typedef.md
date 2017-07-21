### char (*(*x())[5])()

```
  typedef char (*Func)()
  ==> char (*(*x())[5])() ->  Func((*x())[5]
  typedef Func A[5]
  ==> Func((*x())[5] -> A *x()
```