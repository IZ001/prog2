#!/usr/bin/env python3
from heltal import Heltal
import matplotlib.pyplot as plt
from time import perf_counter

def fib_py(n):
    if n <= 1:
        return n
    else:
        return(fib_py(n-1) + fib_py(n-2))

def main():
    time_py = []
    time_c = []
    n = []
    for k in range(30,46):        
        #Python
        t1_start = perf_counter()    # start counter
        fib_py(k)
        t1_stop = perf_counter()     # stop counter
        
        #C++
        t2_start = perf_counter()    # start counter
        f = Heltal(k)
        f.fib()
        t2_stop = perf_counter()     # stop counter        
        
        n.append(k)
        time_py.append(t1_stop - t1_start)
        time_c.append(t2_stop - t2_start)
        
    plt.rcParams["figure.figsize"] = (12,5)
    plt.subplot(121)  
    plt.plot(n, time_py, label = 'Python time')
    plt.title('Computing time of Fibonacci numbers (Python)')
    plt.xlabel('Number')
    plt.ylabel('Computing time in seconds')    
    
    plt.subplot(122)
    plt.plot(n, time_c, label = 'C++ time')
    plt.title('Computing time of Fibonacci numbers (C++)')
    plt.xlabel('Number')
    plt.ylabel('Computing time in seconds')
    #plt.show()  
    
    plt.savefig('graph.png')
    print("C++:")
    print(time_c)
    print("Python:")
    print(time_py)
    
    f = Heltal(47)
    print('Fibonacci-talet för n = 47 med C++-koden ',f.fib())
    
if __name__ == '__main__':
    main()
