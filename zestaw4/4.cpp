#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  const int max=2;
  int tab[max][max];
  tab[0][0]=1;
  tab[0][1]=99;
  tab[1][0]=100;
  tab[1][1]=3;
  int sumkmax=0;
  int sumwmin=0;
  int maxk=0, minw=0;
  for(int i=0; i<max; i++)
    sumwmin+=tab[0][i];
  for(int i=0; i<max; i++)
  {
    int sumktemp=0, sumwtemp=0;
    for(int j=0; j<max; j++)
    {
      sumktemp+=tab[j][i];
      sumwtemp+=tab[i][j];
    }
    if(sumktemp>sumkmax)
    {
      sumkmax=sumktemp;
      maxk=i;
    }
    if(sumwtemp<sumwmin)
    {
      sumwmin=sumwtemp;
      minw=i;
    }
  }
  cout << "Wiersz " << minw << " Kolumna " << maxk << endl; 
  return 0;
}
