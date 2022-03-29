#include <cstdlib>
#include <stdint.h>
// Integer class 

class Heltal{
	public:
		Heltal(int);
		uint64_t fib();
		int get();
		void set(int);
	private:
		int val;
		uint64_t calc_fib(int);
	};
 
Heltal::Heltal(int n){
	val = n;
	}
 
int Heltal::get(){
	return val;
	}
 
void Heltal::set(int n){
	val = n;
	}

uint64_t Heltal::calc_fib(int n) {
    if (n <= 1)
        return n;
    else 
        return (calc_fib(n-1) + calc_fib(n-2));    
    }

uint64_t Heltal::fib() {
    return calc_fib(val);
    }
	
extern "C"{
	Heltal* Heltal_new(int n) {return new Heltal(n);}
	int Heltal_get(Heltal* heltal) {return heltal->get();}
	void Heltal_set(Heltal* heltal, int n) {heltal->set(n);}
	uint64_t Heltal_fib(Heltal* heltal) {return heltal->fib();}
	void Heltal_delete(Heltal* heltal){
		if (heltal){
			delete heltal;
			heltal = nullptr;
			}
		}
	}