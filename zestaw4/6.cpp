#include <iostream>
#include <cmath>
using namespace std;

bool bylo(int tab2[], int n, int max2)
{
  for(int i=0; i<max2; i++)
  {
    if(tab2[i]==n)
      return true;
  }
  return false;
}

int main()
{
  const int max = 10;
  int tab[max][max];
  int tab2[max*max];
  int licz=0;
  for(int i=0; i<max; i++)
  {
    for(int j=0; j<max; j++)
    {
      if(!bylo(tab2, tab[i][j], max*max))
      {
        tab2[licz]=tab[i][j];
        licz++;
      }
    }
  }
  for(int i=0; i<max*max; i++)
  {
    for(int j=0; j<max*max-1; j++)
    {
      if(tab2[j+1]<tab2[j])
      {
        int temp=tab2[j+1];
        tab2[j+1]=tab2[j];
        tab2[j]=temp;
      }
    }
  }
}
