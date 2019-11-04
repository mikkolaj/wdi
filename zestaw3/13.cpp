#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int dlug(int tab[])
{
  int liczr=0, liczm=0; max=0, r;
  r=tab[1]-tab[0];
  for(int i=1; i<10-1; i++)
  {
    if(tab[i+1]-tab[i]==r)
    {
      if(r>0)
      {
        if(liczr==0)
        licz++;
        if(licz>max)
          max=licz;
      }
      else
    }
    else
    {
      r=tab[i+1]-tab[i];
      licz=2;
    }
  }
  return max;
}

int main()
{
  srand(time(NULL));
  const int n=200;
  int tab[n];
  for(int i=0; i<n; i++)
  {
    int temp = rand()%99+1;
    if(temp%2==0)
    {
      if((rand()%2+1)==2)
        tab[i]=temp+1;
      else
        tab[i]=temp-1;
    }
    else
      tab[i]=temp;
  }

return 0;
}
