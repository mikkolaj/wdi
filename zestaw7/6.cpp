#include <iostream>
#include <cmath>
using namespace std;

const int N=6;

bool czypierwsza(int tab[], int start, int koniec)
{
  int suma=0, potega=0, licznik=0;
  for(int i=koniec; i>=start; i--)
  {
    suma+=tab[i]*pow(2, potega);
    potega++;
  }
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
  for(int i=2; i+start<=30 && i+start<N; i++)
  {
    if(!czypierwsza(tab, start, start+i))
      continue;
    else if(start+i==N-1)
      return true;
    if(tnij(tab, start+i))
      return true;
  }
  return false;
}
int main()
{
	int tab[N] = {1, 1, 0, 1, 0, 1};
	cout << tnij(tab, 0);
	return 0;
}
