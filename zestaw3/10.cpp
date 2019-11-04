#include <iostream>
using namespace std;

int dlug(int tab[])
{
	int licz=1, max=0;
	for(int i=0; i<10-1; i++)
	{
		if(tab[i+1]>tab[i])
			{
				licz++;
				if(licz>max)
					max=licz;
			}
		else
			licz=1;
	}
	return max;
}


int main()
{
	int tab[10]={1, 2, 3, -7, -6, 543, 555, 0, 0, 0};
	cout << dlug(tab);
	return 0;
}
