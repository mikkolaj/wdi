#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	const double e=0.0001;
	double num, a=1, b;
	cin >> num;
	b=num;
	while(abs(a-b)>e)
	{
		a=(a+b)/2;
		b=num/a;
		cout << a << endl << b << endl;
	}
	cout << a;
	return 0;
}
