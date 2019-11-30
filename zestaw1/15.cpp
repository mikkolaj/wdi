#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double prev=sqrt(0.5);
	double wyn=prev;
	for(int i=0; i<100; i++)
	{
	  prev=sqrt(0.5+(0.5*prev));
	  wyn*=prev;
  }
  cout << 2/wyn;
}
