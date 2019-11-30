#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num, nc, b=0;
  cin >> num;
  nc = num;
  while(nc>0)  // odwraca liczbe w zapisie binarnym
  {
    b = b << 1; // binary shift w lewo, odpowiada pomnozeniu przez 2
    b = b | (nc&1);
    nc = nc >> 1; // odpowiada dzieleniu calkowitemu przez 2
  }
  if(b==num)
    cout << "Binarnie jest palindromem" << endl;
  else
    cout << "Binarnie nie jest palindromem" << endl;
  return 0;
}
