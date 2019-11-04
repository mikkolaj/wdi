#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  long liczba=1;
  cout << "Podaj n: ";
  cin >> n;
  if(n==0)
  {
    cout << 1;
    return 0;
  }
  else
    for(int i=1; i<=n; i++)
      liczba*=i;
  cout << "n! to: " << liczba << endl;
  return 0;
}
