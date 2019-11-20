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
    for(int dz=2; dz<=tab[i]; dz++)
    {
      if(tab[i]%dz==0)
        suma++;
      while(tab[i]%dz==0)
        tab[i]/=dz;
    }
    tab[i]=suma;
  }
}

bool dasie(int tab[])
{
  nawagi(tab);
  int waga0=0, waga1=0, waga2=0;
  int licznik, suma=0;
  for(int h=0; h<N; h++)
    suma+=tab[h];
  if(suma%3!=0)
    return false;
  for(int i=0; i<pow(3,N); i++)
  {
    int ic=i, licznik=0;
    waga0=0, waga1=0, waga2=0;
    for(int j=0; j<N; j++)
    {
      if(ic%3==0)
        waga0+=tab[licznik];
      else if(ic%3==1)
        waga1+=tab[licznik];
      else if(ic%3==2)
        waga2+=tab[licznik];
      licznik++;
      ic/=3;
    }
    if(waga0==waga1 && waga1==waga2)
    {
      return true;
    }
  }
  return false;
}
int main()
{
  int dane[N]={30, 14, 2, 2, 3, 5};
  cout << dasie(dane);
  return 0;
}
