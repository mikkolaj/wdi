#include <iostream>
using namespace std;


int main()
{
	int k;
	cin >> k;
	double pol = 0;
	const float prec = 0.1;
	for(float i=1; i<k; i+=prec)
	{
		cout << i << endl;
		pol+=1/i*prec;
	}
	cout << pol;
	return 0;
}
