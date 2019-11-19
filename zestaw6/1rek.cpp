#include <iostream>
using namespace std;
const int N=3;
int dane[N]={1, 2, 5};

bool dasie(int tab[], int waga, int start)
{
  if(waga==tab[start])
    return true;
  if(start>N)
    return false;
  return dasie(tab, waga-tab[start], start+1) || dasie(tab, waga, start+1);
}
int main()
{
  cout << dasie(dane, 4, 0) << endl;
  return 0;
}
