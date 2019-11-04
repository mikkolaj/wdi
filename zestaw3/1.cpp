#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int sys, licz;
  cout << "Podaj liczbe i system: ";
  cin >> licz >> sys;
  string wyn;
  /*for(int i=0; i<256; i++)
  {
    cout << i << "    " << char(i) << endl;
  }*/
  while(licz!=0)
  {
    if(licz%sys>9)
      wyn = char((licz%sys)+55) + wyn;
    else
      wyn = char(48+(licz%sys)) + wyn;
    licz/=sys;
  }
  cout << wyn << endl;
}

