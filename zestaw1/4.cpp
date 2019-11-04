#include <iostream>
using namespace std;


int main()
{
	int n, k=1;
	cin >> n;
	while(n>0)
	{
		n-=k;
		k+=2;
	}	
	cout << (k-1)/2;
	return 0;
}
