#include <iostream>
using namespace std;


int main()
{
	int part[3000]={0};
	int sil[3000]={0};
	int n;
	cin >> n;
	sil[3000-1]=1;
	for(int i=1; i<=n; i++)
	{
		int ic=i;
		int licznik=0;
		int sum[3000]={0};
		while(ic!=0)
		{
			for(int j=3000-1; j>=0; j--)
			{

				part[j]= sil[j]*(ic%10);
			}
			for(int j=3000-1; j>=1; j--)
			{
				part[j-1]+=part[j]/10;
				part[j]%=10;
			}
			ic/=10;
			for(int j=3000-1-licznik; j>=0; j--)
			{
				sum[j]+=part[j+licznik];
			}
			for(int j=3000-1; j>=1; j--)
			{
				sum[j-1]+=sum[j]/10;
				sum[j]%=10;
			}
			licznik++;
		}
		for(int j=3000-1; j>=0; j--)
			{
				sil[j]=sum[j];
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
