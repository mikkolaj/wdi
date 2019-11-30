#include <iostream>

using namespace std;

void print_rec(int n, int* stack, int max_el, int index = 0){
	if(n == 0){
		for(int i = 0 ; i < index - 1 ; i++){
			cout << stack[i] << " + ";
		}
		cout << stack[index - 1] << endl;
		return;
	}
	for(int i = max_el ; i >= 1 ; i--){
		stack[index] = i;
		print_rec(n-i, stack, i > n-i?n-i:i, index+1);
	}
}

void print(int n){
	int stack[n];
	print_rec(n, stack, n-1);
}


int main(){
  print(5);
}
