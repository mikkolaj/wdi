#include <iostream>
using namespace std;


int main()
{
	long sil[3000]={0};
	long dzielnik = 10;
	long carry=0;
	int n;
	cin >> n;
	sil[0]=1;
	int koniec=0;
	
	for(int i=2; i<=n; i++)
	{
	  for(int j=0; j<=koniec; j++)
	  {
	    long temp=sil[j]*i+carry;
	    sil[j]=(temp)%dzielnik;
	    carry=temp/dzielnik;
	    if(carry!=0 && j==koniec)
	     koniec++;
    }
  }
  
  for(int i=koniec; i>=0; i--)
    cout << sil[i];
	return 0;
}
