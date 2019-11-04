#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int t[1000];
  for(int i=0; i<1000; i++)
  {
    t[i]=i+1;
    int ic=i+1;
    while(ic!=0)
    {
      if((ic%10)%2==1)
      {
        cout << i+1 << " ma nieparzysta" << endl;
        break;
      }
      ic/=10;
    }
  }
  return 0;
}
