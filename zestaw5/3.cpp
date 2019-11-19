#include <iostream>
using namespace std;

struct hetman
{
  int w;
  int k;
};

struct dane
{
  hetman t[100];
  int N;        
};

bool nieszach(dane poloz)
{
  for(int i=0; i<poloz.N; i++)
  {
    for(int j=i+1; j<poloz.N; j++)
    {
      if(poloz.t[i].k==poloz.t[j].k || poloz.t[i].w==poloz.t[j].w || abs(poloz.t[i].k-poloz.t[j].k)==abs(poloz.t[i].w-poloz.t[j].w))
        return false;
    }
  }
  return true;
}

int main()
{
  dane heti;
  heti.N=3;
  heti.t[0].k=50;
  heti.t[0].w=0;
  heti.t[1].k=0;
  heti.t[1].w=10;
  heti.t[2].k=1;
  heti.t[2].w=11;
  cout << nieszach(heti);
  return 0;
}
