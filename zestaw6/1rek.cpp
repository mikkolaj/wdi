#include <iostream>
using namespace std;
const int N=3;

bool dasie(int tab[], int waga, int start)
{
  if(waga==0)
    return true;
  if(start==N)
    return false;
  return dasie(tab, waga-tab[start], start+1) || dasie(tab, waga, start+1);
}
int main()
{
  int dane[N]={1, 2, 5};
  cout << dasie(dane, 8, 0) << endl;
  return 0;
}
