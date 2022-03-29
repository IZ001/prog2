#!/usr/bin/env python3
from heltal import Heltal

def fib_py(n):
    if n <= 1:
        return n
    else:
        return(fib_py(n-1) + fib_py(n-2))

def main():
    f = Heltal(5)
    print(f.get())
    f.set(7)
    print(f.get())
    #C++
    print(f.fib())
    #Python
    print(fib_py(f.get()))
    
    
    
    
if __name__ == '__main__':
    main()
