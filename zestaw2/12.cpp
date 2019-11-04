#include <iostream>
using namespace std;


int main()
{
	int num;
	cin >> num;
	while(num>9)
	{
		if(num%10<=num/10%10)
		{
			cout << "Nie" << endl;
			return 0;
		}
		num/=10;
	}	
	cout << "Tak" << endl;
	return 0;
}
