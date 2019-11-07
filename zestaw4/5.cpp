#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  const int max=3;
  int tab[max][max];
  tab[2][0]=5;
  tab[2][1]=2;
  tab[2][2]=-5;
  tab[1][0]=6;
  tab[1][1]=-1;
  tab[1][2]=-6;
  tab[0][0]=7;
  tab[0][1]=-3;
  tab[0][2]=-7;

  int maxk, mink, maxuw, mindw;
  int maxki=-1, minki=-1, maxuwi=-1, mindwi=-1;
  for(int i=0; i<max; i++)
  {
    int sumw=0;
    for(int j=0; j<max; j++)
    {
      sumw+=tab[i][j];
    }
    if(sumw>0)
    {
      mindw=sumw;
      mindwi=i;
    }
    if(sumw<0)
    {
      maxuw=sumw;
      maxuwi=i;
    }
  }
  int sumk1=0;
  for(int i=0; i<max; i++)
  {
    sumk1+=tab[i][0];
  }
  maxk=sumk1;
  mink=sumk1;
  maxki=0;
  minki=0;
  for(int i=0; i<max; i++)
  {
    int sumk=0, sumw=0;
    for(int j=0; j<max; j++)
    {
      sumk+=tab[j][i];
      sumw+=tab[i][j];
    }
    if(sumk>maxk)
    {
      maxk=sumk;
      maxki=i;
    }
    if(sumk<mink)
    {
      mink=sumk;
      minki=i;
    }
    if(sumw>0)
    {
      if(sumw<mindw)
      {
        mindw=sumw;
        mindwi=i;
      }
    }
    if(sumw<0)
    {
      if(sumw>maxuw)
      {
        maxuw=sumw;
        maxuwi=i;
      }
    }
  }
  if(1.0*maxk/mindw>1.0*mink/maxuw)
    cout << "Wiersz " << mindwi << " Kolumna " << maxki << endl; 
  else
    cout << "Wiersz " << maxuwi << " Kolumna " << minki << endl; 
  return 0;
}
