#include <iostream>
using namespace std;

int main()
{
  int n, a, b;
  cin >> a >> b >> n;
  cout << (a/b) << ".";
  for(int i=0; i<n; i++)
  {
    a = (a%b)*10;
    cout << a/b;
  }
  return 0;
}
