#include <iostream>
#include <cmath>
using namespace std;

const int N=6;

bool czypierwsza(int tab[], int start, int koniec)
{
  int suma=0, licznik=0;
  for(int i=start; i<=koniec; i++)
    suma=suma*2+tab[i];
  if(suma==0 || suma==1)
    return false;
  for(int i=2; i*i<=suma; i++)
  {
    while(suma%i==0)
    {
      suma/=i;
      licznik++;
    }
  }
  if(licznik==0)
    return true;
  else
    return false;
}

bool tnij(int tab[], int start)
{
  for(int i=start+2; i<=30 && i<=N; i++)
  {
    if(czypierwsza(tab, start, i-1))
    {  
      if(i==N)
        return true;
      if(tnij(tab, i))
        return true;
    }
  }
  return false;
}
int main()
{
  int tab[N] = {1, 1, 1, 0, 1, 1};
  cout << tnij(tab, 0);
  return 0;
}
