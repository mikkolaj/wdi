#include <iostream>
#include <cmath>
using namespace std;

bool parz(int n)
{
  if(n==0)
    return true;
  while(n!=0)
  {
    if(n%10%2==0)
      return true;
    n/=10;
  }
  return false;
}

int main()
{
  const int max = 2;
  int tab[max][max];
  bool jest = true;
  tab[0][0]=12;
  tab[0][1]=11;
  tab[1][0]=12;
  tab[1][1]=12;
  for(int i=max-1; i>=0; i--)
  {
    jest=true;
    for(int j=0; j<max; j++)
    {
      if(!parz(tab[i][j]))
      {
        jest=false;
        break;
      }
    }
    if(jest)
    {
      cout << "Tak" << endl;
      return 0;
    }
  }
  cout << "Nie" << endl;
  return 0;
}
