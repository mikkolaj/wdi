#include <iostream>
#include <cmath>
using namespace std;
const int N=6;

void nawagi(int tab[])
{
  int suma;
  for(int i=0; i<N; i++)
  {
    suma=0;
    for(int dz=2; dz*dz<=tab[i]; dz++)
    {
      if(tab[i]%dz==0)
        suma++;
      while(tab[i]%dz==0)
        tab[i]/=dz;
    }
    if(tab[i]>1)
      suma++;
    tab[i]=suma;
  }
}

bool podzial(int tab[], int sw1, int sw2, int sw3, int start)
{
  if(start==N)
    return (sw1==sw2 && sw2==sw3);
  return podzial(tab, sw1+tab[start], sw2, sw3, start+1) || 
    podzial(tab, sw1, sw2+tab[start], sw3, start+1) ||
    podzial(tab, sw1, sw2, sw3+tab[start], start+1);
}

bool wywol(int tab[])
{
  nawagi(tab);
  int suma=0;
  for(int h=0; h<N; h++)
    suma+=tab[h];
  if(suma%3!=0)
    return false;
  return podzial(tab, 0, 0, 0, 0);
}
int main()
{
  int dane[N]={29, 14, 2, 2, 3, 5};
  cout << wywol(dane) << endl;
  return 0;
}
