#include <iostream>
using namespace std;

const int N=6;

int sumuj(int tab[], int start, int sumael, int sumaind, int liczba, int &mina, int &wyn)
{
//  cout << start << " " << liczba << endl;
//  cout << sumaind << " " << sumael << endl;
//  cout << sumaind+start << " " << sumael+tab[start] << endl << endl;
  if(sumaind+start==sumael+tab[start])
  {
    if(liczba<mina)
    {
      wyn=sumaind+start;
      mina=liczba;
    }
  }
  if(start+1<N)
  {
  sumuj(tab, start+1, sumael+tab[start], sumaind+start, liczba+1, mina, wyn);
  sumuj(tab, start+1, sumael, sumaind, liczba, mina, wyn);
  }
  return wyn;
}

int main()
{
  int mina=N+1;
  int wyn=-1;
	int tab[6]={1, 7, 3, 5, 11, 2};
	cout << sumuj(tab, 0, 0, 0, 1, mina, wyn);
	return 0;
}
