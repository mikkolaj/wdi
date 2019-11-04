#include <iostream>
using namespace std;

int a(int n);
int b(int n);

int main()
{
	int n, i=0;
	while(cin >> n && a(i)==n)
	{
		cout << b(i) << endl;
		i++;
	}
}

int a(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return a(n-1) - b(n-1)*a(n-2);
}

int b(int n)
{
	if(n==0)
		return 2;
	else
		return b(n-1) + 2*a(n-1);
}
