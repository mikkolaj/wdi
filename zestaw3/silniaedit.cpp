#include <iostream>
using namespace std;


int main()
{
	int part[3000]={0};
	int sil[3000]={0};
	int n;
	cin >> n;
	sil[3000-1]=9;
	sil[3000-2]=9;
	sil[3000-3]=9;
	for(int i=n; i<=n; i++)
	{
		int ic=i;
		int licznik=0;
		int part[3000]={0};
		while(ic!=0)
		{
			for(int j=3000-1; j>=0; j--)
			{

				part[j-licznik]+=sil[j]*(ic%10);
			}
			for(int j=3000-1; j>=1; j--)
			{
				part[j-1]+=part[j]/10;
				part[j]%=10;
			}
			ic/=10;
			licznik++;
	bool cos=0;
	for(int z=0; z<3000; z++)
	{
		if(part[z]!=0)
			cos=1;
		if(cos)
			cout << part[i];
	}
	cout << endl;
		}
		for(int j=3000-1; j>=0; j--)
			{
				sil[j]+=part[j];
			}
		for(int j=3000-1; j>=1; j--)
			{
				sil[j-1]+=sil[j]/10;
				sil[j]%=10;
			}
	}
	bool zero=0;
	for(int i=0; i<3000; i++)
	{
		if(sil[i]!=0)
			zero=1;
		if(zero)
			cout << sil[i];
	}
	return 0;
}
