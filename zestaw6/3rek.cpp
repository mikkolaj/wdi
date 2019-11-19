#include <iostream>
using namespace std;
const int N=3;
int dane[N]={1, 2, 5};

bool dasie(int tab[], int waga, int start)
{
  if(waga==tab[start])
  {
    cout << tab[start] << endl;
    return true;
  }
  if(start>N)
    return false;
  if(dasie(tab, waga-tab[start], start+1) || dasie(tab, waga, start+1) || dasie(tab, waga+tab[start], start+1))
  {
    cout << tab[start] << endl;
    return true;
  }
}
int main()
{
  dasie(dane, 6, 0);
  return 0;
}
