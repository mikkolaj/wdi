#include <iostream>
using namespace std;

int nwd(int a, int b)
{
  while(a!=0)
  {
    int c=a;
    a=b%a;
    b=c;
  }
  return b;
}


int main()
{
  cout << nwd(15, 5);
  return 0;
}
