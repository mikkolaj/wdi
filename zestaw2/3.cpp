#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num, nc, b=0;
  cin >> num;
  nc = num;
  while(nc>0)
  {
    b*=10;
    b+=nc%10;
    nc/=10;
  }
  if(b==num)
    cout << "Jest palindromem" << endl;
  else
    cout << "Nie jest palindromem" << endl;
  return 0;
}
