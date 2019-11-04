#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int sumc, sumdz;
  for(int i=1; i<100; i++)
  {
    sumc=0;
    sumdz=0;
    int ic=i;
    while(ic!=0)
    {
      sumc+=ic%10;
      ic/=10;
    }
    ic = i;
    int k=2;
    while(ic!=1)
    {
      while(ic/k*k==ic)
      {
        int kc=k;
        while(kc!=0)
        {
          sumdz+=kc%10;
          kc/=10;
        }
        ic/=k;
      }
      k++;
    }
    if(sumdz==sumc)
      cout << i << endl;
  }
}

