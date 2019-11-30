#include <iostream>
using namespace std;

int main()
{
  int suma=INT_MAX;
  int iwyn, jwyn;
  for(int i=1; i<=2019; i++)
  {
    for(int j=0; i+j<=2019; j++)
    {
      int prev=i, fib=j;
    	while(fib<=2019)
      {
    		fib=fib+prev;
    		prev=fib-prev;
    	}
    	if(prev==2019)
    	{
    	  if(i+j<suma)
    	  {
    	    suma=i+j;
    	    iwyn=i;
    	    jwyn=j;
        }
      }
    }
  }
  cout << iwyn << " " << jwyn << endl;
	
	return 0;
}
