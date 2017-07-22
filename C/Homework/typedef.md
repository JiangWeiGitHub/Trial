### char (*(*x())[5])()

```
  typedef char (*Func)()
  ==> char (*(*x())[5])() ->  Func((*x())[5]

  typedef Func A[5]
  ==> Func((*x())[5] -> A *x()
```


### void (*signal(int signo, void (*func)(int)))(int)

```
  typedef void (*FuncPointer)(int)
  ==> void (*signal(int signo, void (*func)(int)))(int) -> void (*signal(int signo, FuncPointer))(int)
```