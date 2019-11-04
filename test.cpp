#include <iostream>
#include <cmath>
using namespace std;
unsigned const long long int ile=1000000000;
bool tab[ile];

int main()
{
	for(unsigned long long int i=2; i<ile; i++)
	{
		if(!tab[i])
		{
			unsigned long long int ic=2*i;
			while(ic<ile)
			{
				tab[ic]= true;
				ic+=i;
			}
		}
	}
	long int cyf=1;
	unsigned long long int wiel=10;
	for(unsigned long long int j=2; j<ile; j++)
	{
		if(j>=wiel)
		{
			cyf++;
			wiel*=10;
		}
		if(!tab[j])
		{
			unsigned long long int sum=0, jc=j;
			while(jc!=0)
			{
				sum+=pow(jc%10, cyf);
				jc/=10;
			}
			if(sum==j)
				cout << j << endl;
		}
	}
	return 0;
}
