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

bool nastepny(bool kol[], bool skos1[], bool skos2[], int y, int x, bool ust[][N])
{
  if(!zbanowany(kol, skos1, skos2, y, x))
  {
    kol[x]=skos1[(2*N-1)/2+y-x]=skos2[x+y]=ust[y][x]=true;
    if(y<N-1)
    {
      for(int i=2; i<N; i++)
      {
        if(x-i>=0)
          if(nastepny(kol, skos1, skos2, y+1, x-i, ust))
            return true;
        if(x+i<N)
          if(nastepny(kol, skos1, skos2, y+1, x+i, ust))
            return true;
      }
    }
    else
      return true;
    kol[x]=skos1[(2*N-1)/2+y-x]=skos2[x+y]=ust[y][x]=false;
  }
}

void wypisz(bool ust[][N])
{
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

void wrap(bool kol[], bool skos1[], bool skos2[], bool ust[][N])
{
  for(int i=0; i<8; i++)
  {
    if(nastepny(kol, skos1, skos2, 0, i, ust))
    {
      wypisz(ust);
      break;
    }
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
