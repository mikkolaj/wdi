#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	const double e=0.0001;
	double num, a=1;
	cin >> num;
	double b=(a*a+num)/(2*a);
	while(abs(a-b)>e)
	{
	  a=b;
		b=(a*a+num)/(2*a);
		cout << a << endl;
	}
	cout << a;
	return 0;
}
