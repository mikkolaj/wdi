#include <iostream>
using namespace std;


int main()
{
	int fib1=1, prev1=0;
	int fib2=1, prev2=0;
	int sum;
	cin >> sum;
	sum+=1;
	while(1)
	{
    int akt=0;
		while(1)
		{
		  if(akt==sum)
		    break;
		  if(akt<sum)
		  {
		    akt+=fib1;
		    fib1+=prev1;
		    prev1=fib1-prev1;
      }
      else if(akt>sum)
      {
        akt-=fib2;
		    fib2+=prev2;
		    prev2=fib2-prev2;
      }
      cout << akt << " " << sum << endl;
      if(fib1!=1 && fib2==fib1)
		  {
		    cout << sum << endl;
		    return 0;
      }
    }
		sum++;
		fib1=1, prev1=0;
		fib2=1, prev2=0;
	}
	return 0;
}
