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
    bool parz=false;
    while(ic!=0)
    {
      if((ic%10)%2==0)
      {
        parz=true;
        break;
      }
      ic/=10;
    }
    if(!parz)
      cout << t[i] << endl;
  }
  return 0;
}
