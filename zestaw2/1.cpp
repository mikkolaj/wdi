#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int fib1=1, prev1=0, num;
  int fib2=1, prev2=0;
  cin >> num;
  if(num==0 || num==1)
  {
    cout << "tak" << endl;
    return 0;
  }
  while(fib1<=num)
  {
    while(fib2<fib1 && fib1*fib2)
    {
      if(fib1*fib2==num)
      {
        cout << "tak" << endl;
        return 0;
      }
      cout << "debil" << endl;
      fib2+=prev2;
      prev2=fib2-prev2;
    }
    fib1+=prev1;
    prev1=fib1-prev1;
    fib2=1;
    prev2=0;
  }
  cout << "nie" << endl;
  return 0;
}
