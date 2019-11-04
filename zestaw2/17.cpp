#include <iostream>
#include <cmath>
using namespace std;

bool pierwsza(int n)
{
  if(n<2)
    return false;
  if(n==2)
    return true;
  for(int i=2; i*i<=n; i++)
    if(n%i==0)
      return false;
  return true;
}

int main()
{
  int cyf, sum, licznik=0;
  cin >> cyf;
  for(int i=2; licznik<7; i++)
  {
    if(pierwsza(i))
    {
      sum=0;
      int ic = i;
      while(ic!=0 && sum <= i)
      {
        sum+=pow(ic%10,cyf);
        ic/=10;
      }
      if(sum==i)
        cout << sum << endl;
    }
  }
}

