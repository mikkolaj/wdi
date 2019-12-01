#include <iostream>
#include <cmath>
using namespace std;

bool niep(int n)
{
  if(n==0)
    return false;
  while(n!=0)
  {
    if(n%10%2==0)
      return false;
    n/=10;
  }
  return true;
}

int main()
{
  const int max = 2;
  int tab[max][max]={};
  tab[0][0]=37957;
  tab[1][1]=37;
  int licznik=0;
  for(int i=max-1; i>=0; i--)
  {
    for(int j=0; j<max; j++)
    {
      if(niep(tab[i][j]))
      {
        licznik++;
        break;
      }
    }
  }
  if(licznik==max)
    cout << "Tak" << endl;
  else
    cout << "Nie" << endl;
  return 0;
}
