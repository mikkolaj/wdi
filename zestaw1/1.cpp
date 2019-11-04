#include <iostream>
using namespace std;

int main(){
	int fib=1, prev=0;
	const int max_fib = 1000000;
	cout << prev << endl;
	
	while(fib<max_fib){
		cout << fib << endl;
		const int temp = prev;
		prev = fib;
		fib = fib + temp;
	}
	
	return 0;
}
