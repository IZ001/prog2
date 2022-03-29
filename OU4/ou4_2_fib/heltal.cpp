#include <cstdlib>
// Integer class 

class Heltal{
	public:
		Heltal(int);
		int fib();
		int get();
		void set(int);
	private:
		int val;
		int calc_fib(int);
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

int Heltal::calc_fib(int n) {
    if (n <= 1)
        return n;
    else 
        return (calc_fib(n-1) + calc_fib(n-2));    
    }

int Heltal::fib() {
    return calc_fib(val);
    }
	
extern "C"{
	Heltal* Heltal_new(int n) {return new Heltal(n);}
	int Heltal_get(Heltal* heltal) {return heltal->get();}
	void Heltal_set(Heltal* heltal, int n) {heltal->set(n);}
	int Heltal_fib(Heltal* heltal) {return heltal->fib();}
	void Heltal_delete(Heltal* heltal){
		if (heltal){
			delete heltal;
			heltal = nullptr;
			}
		}
	}