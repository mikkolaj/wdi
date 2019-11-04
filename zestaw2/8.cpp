#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n, a, b;
  cin >> a >> b>> n;
  cout << (a/b) << ".";
  a = (a%b)*10;

  for(int i=0; i<n; i++)
  {
    cout << a/b;
    a = (a%b)*10;
  }

  return 0;
}
