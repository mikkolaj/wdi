#include <iostream>
using namespace std;

bool jestczyn(int t, int n)
{
	if(t%n==0)
	{
		for(int i=2; i*i<=n; i++)
			if(n%i==0)
				return false;
		return true;
	}
	else
		return false;
}

bool traverse(int tab[], int cur, int size)
{
	int i=2;
	while(cur+i<size)
	{
		if(jestczyn(tab[cur],i))
			if(cur+i==size-1)
			{
				cout << cur << endl << i << endl;
				return true;
			}
			else
			{
				//cout << cur << endl << i << endl;
				if(traverse(tab, cur+i, size))
					return true;
			}
		i++;
	}
	return false;
}

int main()
{
	int tab[8]={9, 81, 81, 8, 81, 0, 81, 8};
	int tab2[9]={6, 113, 113, 6, 113, 113, 2, 113, 113};
	cout << traverse(tab2, 0, 9);
	return 0;
}
