#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int num, licznik=0;
	cin >> num;
	for(int j=1; j<=num; j++)
	{
	  int jc=j;
  	for(int i=2; i<=5; i++)
  	{ 
  		while(jc%i==0)
  			jc/=i;
  	}
  	if(jc==1)
  	 licznik++;
  }
	cout << "W przedziale od 1 do " << num << " takich liczb jest: " << licznik << endl;
	return 0;
}
