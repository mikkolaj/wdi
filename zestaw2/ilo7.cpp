#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num, a;
  cin >> num;
  a = sqrt(num);
  /*
  for(int i=2; i<=num/2; i++)
  {
    if(num%i==0 && del==-1)
    {
      del = abs(num/i-i);
      a = num/i;
      b = i;
    }
    else if(num%i==0)
    {
      if(abs(num/i-i)<del)
      {
        del = abs(num/i-i);
        a = num/i;
        b = i;
      }
    }
  }*/
  while(a>0)  // wersja optymalna
  {
    if(num/a*a==num)
    {
      cout << "a: " << a << " b " << num/a  << endl;
      return 0;
    }
    a--;
  }

  return 0;
}
