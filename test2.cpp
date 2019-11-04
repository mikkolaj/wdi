#include <iostream>
#include <cmath>
using namespace std;
unsigned const long long int ile=1000;
bool tab[ile];

int main()
{
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
