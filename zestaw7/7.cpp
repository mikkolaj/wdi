#include <iostream>
using namespace std;

const int N=6;

int sumuj(int tab[], int start, int sumael, int sumaind)
{
  for(int i=0; i+start<N; i++)
  {
    if(sumaind+i==sumael+tab[i])
      return true;
    if(sumuj(tab, start+i, sumael+tab[i], sumaind+i) || sumuj(tab, start+i, sumael+tab[i], sumaind+i))
      return true;
  }
  return false;
}

int main()
{
	
	return 0;
}
