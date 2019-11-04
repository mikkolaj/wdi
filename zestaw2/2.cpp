#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int num;
	cin >> num;
	int i=1;
	while((i*i+i+1)<=num)
	{
		if(num%(i*i+i+1)==0)
		{
			cout << "tak " << endl;
			return 0;
		}
		i++;
	}
	cout << "nie" << endl;
	return 0;
}
