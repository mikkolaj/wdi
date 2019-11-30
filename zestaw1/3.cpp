#include <iostream>
using namespace std;


int main()
{
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
  }
  cout << "Nie jest";
  return 0;
}
