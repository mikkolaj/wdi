#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	const int max=4;
	int tab[max][max]={};
	int liczba=1, x=max/2, y=max/2, licznik=1;
	if(max%2==0)
	{
		x--;
		y--;
	}
	tab[max/2][max/2]=0;
	for(int j=0; j<max/2; j++)
	{
		for(int i=1; i<=licznik; i++)
		{
			
			tab[y+1][x]=liczba;
			y++;
			liczba++;
		}
		for(int i=1; i<=licznik; i++)
		{
			
			tab[y][x+1]=liczba;
			x++;
			liczba++;
		}
		licznik++;
		for(int i=1; i<=licznik; i++)
		{
			
			tab[y-1][x]=liczba;
			y--;
			liczba++;
		}
		if(max%2==0 && j+1==max/2)
			break;
		for(int i=1; i<=licznik; i++)
		{
			
			tab[y][x-1]=liczba;
			x--;
			liczba++;
		}
		licznik++;
	}
	if(max%2!=0)
	{
		while(y<max-1)
		{
			y++;
			tab[y][x]=liczba;
			liczba++;
		}
	}
	int szer = int(log10(max*max))+3;
	for(int i=max-1; i>=0; i--)
	{
		for(int j=0; j<max; j++)
		{
			cout.width(szer);
			cout << tab[i][j];
		}
		cout << endl;
	}
	return 0;
}
