#include <iostream>
using namespace std;

const int N=8;

bool zbanowany(bool kol[], bool skos1[], bool skos2[], int y, int x)
{
  if(kol[x] || skos1[(2*N-1)/2+y-x] || skos2[x+y])
    return true;
  else
    return false;
}

void nastepny(bool kol[], bool skos1[], bool skos2[], int y, int x, bool ust[][N], bool &udane)
{
  if(!zbanowany(kol, skos1, skos2, y, x))
  {
    kol[x]=skos1[(2*N-1)/2+y-x]=skos2[x+y]=ust[y][x]=true;
    if(y<N-1)
    {
      for(int i=2; i<N; i++)
      {
        if(x-i>=0 && !udane)
          nastepny(kol, skos1, skos2, y+1, x-i, ust, udane);
        if(x+i<N && !udane)
          nastepny(kol, skos1, skos2, y+1, x+i, ust, udane);
        if(udane)
          return;
      }
    }
    else
    {
      udane=true;
      return;
    }
    kol[x]=skos1[(2*N-1)/2+y-x]=skos2[x+y]=ust[y][x]=false;
  }
}

void wrap(bool kol[], bool skos1[], bool skos2[], bool ust[][N])
{
  bool udane=false;
  for(int i=0; i<8 && !udane; i++)
  {
    nastepny(kol, skos1, skos2, 0, i, ust, udane);
  }
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      cout.width(2);
      cout << ust[i][j];
    }
    cout << endl;
  }
}

int main()
{
  bool kol[N]={}, skos1[2*N-1]={}, skos2[2*N-1]={};
  int suma=1;
  bool ust[N][N]={};
  wrap(kol, skos1, skos2, ust);
  return 0;
}
