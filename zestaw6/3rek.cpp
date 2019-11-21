#include <iostream>
using namespace std;
const int N=4;

void dasie(int tab[], int waga, int start, string lewo, string prawo)
{
  if(start==N)
  {
    if(waga==0)
      cout << lewo << endl << prawo << endl << endl;
    return;
  }
  dasie(tab, waga-tab[start], start+1, lewo+"1", prawo+"0");
  dasie(tab, waga, start+1, lewo+"0", prawo+"0");
  dasie(tab, waga+tab[start], start+1, lewo+"0", prawo+"1");
}
int main()
{
  int dane[N]={1, 5, 10, 15};
  dasie(dane, 10, 0, "", "");
  return 0;
}
