#include <iostream>
using namespace std;


int main()
{
<<<<<<< HEAD
	int fib1=1, prev1=0;
	int fib2=1, prev2=0;
	int sum;
	cin >> sum;
	int akt=0;
	while(1)
	{
		if(akt==sum)
		{
			cout << "Jest";
			return 0;
		}
		if(akt<sum)
=======
  int fib1=1, prev1=0;
  int fib2=1, prev2=0;
  int sum;
  cin >> sum;
  int akt=0;
  while(fib1>=fib2 && akt>=0)
  {
    if(akt==sum)
    {
      cout << "Jest";
      return 0;
    }
    if(akt<sum)
>>>>>>> 91598719fc409f400ef6f1acfa7661a02946ba06
    {	
      akt+=fib1;
      fib1+=prev1;
      prev1=fib1-prev1;
    }
    else if(akt>sum)
    {
      akt-=fib2;
      fib2+=prev2;
<<<<<<< HEAD
		  prev2=fib2-prev2;
		}
		if(fib1==fib2 && fib1!=1)
      break;
		cout << fib1 << " " << fib2 << endl;
=======
      prev2=fib2-prev2;
    }
>>>>>>> 91598719fc409f400ef6f1acfa7661a02946ba06
  }
  cout << "Nie jest";
  return 0;
}
