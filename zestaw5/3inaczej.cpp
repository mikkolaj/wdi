#include <iostream>
using namespace std;

bool kol[100], wier[100], uk1[199], uk2[199];

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
    if(kol[poloz.t[i].k])
      return false;
    if(wier[poloz.t[i].w])
      return false;
    if(uk1[poloz.t[i].w+poloz.t[i].k])
      return false;
    if(uk2[99+poloz.t[i].w-poloz.t[i].k])
      return false;
    kol[poloz.t[i].k]=true;
    wier[poloz.t[i].w]=true;
    uk1[poloz.t[i].w+poloz.t[i].k]=true;
    uk2[99+poloz.t[i].w-poloz.t[i].k]=true;
  }
  return true;
}

int main()
{
  dane heti;
  heti.N=3;
  heti.t[0].k=20;
  heti.t[0].w=20;
  heti.t[1].k=18;
  heti.t[1].w=22;
  heti.t[2].k=1;
  heti.t[2].w=11;
  cout << nieszach(heti);
  return 0;
}
