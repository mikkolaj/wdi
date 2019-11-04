#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	const int max=2;
	int tab[max][max];
	tab[0][0]=1;
	tab[0][1]=99;
	tab[1][0]=100;
	tab[1][1]=3;
	float sumk[max]={}, sumw[max]={}, maxi=0;
	int maxk, maxw;
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
			sumk[i]+=tab[j][i];
			sumw[i]+=tab[i][j];
		}
	}
	for(int i=0; i<max; i++)
	{
		for(int j=0; j<max; j++)
		{
			if(sumk[j]/sumw[i]>maxi)
			{
				maxi=sumk[j]/sumw[i];
				maxk=j;
				maxw=i;
			}
		}
	}
	cout << "Wiersz " << maxw << " Kolumna " << maxk << endl; 
	return 0;
}
