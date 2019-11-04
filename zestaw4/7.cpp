#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  const int max = 10;
  int tab[max][max];
  int tab2[max*max];
  for(int i=0; i<max; i++)
  {
    for(int j=0; j<max; j++)
    {
        tab2[licz]=tab[i][j];
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
