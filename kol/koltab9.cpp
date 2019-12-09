#include <iostream>
#include <cmath>

using namespace std;
const int N=9;

bool czypierwsza(int a)
{
  if(a<2)
    return false;
  else if(a==2)
    return true;
  else
  {
    for(int i=2; i*i<=a; i++)
    {
      if(a%i==0)
        return false;
    }
  }
  return true;
}

bool wyst(int wyn[], int koniec,  int i)
{
  for(int j=0; j<=koniec; j++)
  {
    if(wyn[j]==i)
      return true;
  }
  return false;
}

void wypisz(int wyn[])
{
  for(int i=0; i<N; i++)
    cout << wyn[i] << " ";
  cout << endl;
}

void tabl(int wyn[], int start)
{
  if(start==9)
  {
    wypisz(wyn);
    return;
  }
  for(int i=1; i<=N; i++)
  {
    if(abs(wyn[start-1]-i)>=2 && (!czypierwsza(wyn[start-1]) || !czypierwsza(i)) && !wyst(wyn, start-1, i))
    {
      wyn[start]=i;
      tabl(wyn, start+1);
    }
  }
}

int main()
{
  int wyn[9]={};
  wyn[0]=1;
  tabl(wyn, 1);
  return 0;
}
