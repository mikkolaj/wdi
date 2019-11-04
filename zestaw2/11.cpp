#include <iostream>
using namespace std;

int wyraz(int n)
{
	if(n==1)
		return 2;
	else
		return 3*(wyraz(n-1))+1;
}

int main()
{
	int num, i=1;
	cin >> num;
	while(wyraz(i)<=num)
	{
		if(num%wyraz(i)==0)
		{
			cout << "Tak" << endl;
			return 0;
		}
		i++;
	}
	cout << "Nie" << endl;
	return 0;
}
