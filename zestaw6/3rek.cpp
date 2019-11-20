#include <iostream>
using namespace std;
const int N=4;

bool dasie(int tab[], int waga, int start)
{
  if(waga==tab[start])
  {
    cout << tab[start] << endl;
    return true;
  }
  if(start>=N)
    return false;
  if(dasie(tab, waga-tab[start], start+1) || dasie(tab, waga, start+1) || dasie(tab, waga+tab[start], start+1))
  {
    cout << tab[start] << endl;
    return true;
  }
}
int main()
{
  int dane[N]={1, 5, 10, 15};
  dasie(dane, 9, 0);
  return 0;
}
