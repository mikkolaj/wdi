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
  int tab[max][max];
  bool nie = false;
  for(int i=max-1; i>=0; i--)
  {
    for(int j=0; j<max; j++)
    {
      if(niep(tab[i][j]))
      {
        cout << "Tak" << endl;
        nie=1;
        break;
      }
    }
    if(!nie)
      cout << "Nie" << endl;
    else
      nie = false;
  }
  return 0;
}
