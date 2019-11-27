#include <iostream>
using namespace std;

const int N=8;

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
  cout << endl;
}

bool zbanowany(bool kol[], bool skos1[], bool skos2[], int y, int x)
{
  if(kol[x] || skos1[(2*N-1)/2+y-x] || skos2[x+y])
    return true;
  else
    return false;
}

void nastepny(bool kol[], bool skos1[], bool skos2[], int y, int x, bool ust[][N], int &zlicz)
{
  if(!zbanowany(kol, skos1, skos2, y, x))
  {
    kol[x]=skos1[(2*N-1)/2+y-x]=skos2[x+y]=ust[y][x]=true;
    if(y<N-1)
    {
      for(int i=2; i<N; i++)
      {
        if(x-i>=0)
          nastepny(kol, skos1, skos2, y+1, x-i, ust, zlicz);
        if(x+i<N)
          nastepny(kol, skos1, skos2, y+1, x+i, ust, zlicz);
      }
    }
    else
    {
      zlicz++;
      wypisz(ust);
      kol[x]=skos1[(2*N-1)/2+y-x]=skos2[x+y]=ust[y][x]=false;
      return;
    }
    kol[x]=skos1[(2*N-1)/2+y-x]=skos2[x+y]=ust[y][x]=false;
  }
}

void wrap(bool kol[], bool skos1[], bool skos2[], bool ust[][N], int &zlicz)
{
  for(int i=0; i<8; i++)
    nastepny(kol, skos1, skos2, 0, i, ust, zlicz);
  cout << "Ustawien (wszystkich) bylo " << zlicz << endl;
}

int main()
{
  bool kol[N]={}, skos1[2*N-1]={}, skos2[2*N-1]={};
  int suma=1;
  bool ust[N][N]={};
  int zlicz=0;
  wrap(kol, skos1, skos2, ust, zlicz);
  return 0;
}
