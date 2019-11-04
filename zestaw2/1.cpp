#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int fib1=1, prev1=0, num;
  int fib2=1, prev2=0;
  cin >> num;
  while(fib1<=num)
  {
    if(fib1*fib2==num)
    {
      cout << "tak" << endl;
      return 0;
    }
    while(fib2<fib1)
    {
      cout << "debil" << endl;
      int temp2;
      temp2 = prev2;
      prev2=fib2;
      fib2+=temp2;
      cout << fib1 << "    " << fib2 << endl;
      if(fib1*fib2==num)
      {
        cout << "tak" << endl;
        return 0;
      }

    }
    int temp1;
    temp1 = prev1;
    prev1 = fib1;
    fib1+= temp1;
    fib2=1;
    prev2=0;
  }
  cout << "nie" << endl;
  return 0;
}
