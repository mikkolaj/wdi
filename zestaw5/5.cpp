#include <iostream>
#include <fstream>
using namespace std;

const int maxa=12;
const int size=31;
struct punkt {
  int x;
  int y;
};
struct dane {
  punkt tab[maxa];
  int N;
};

bool tab[31][31];

int licz(bool tab[][size], int y, int x, int dod)
{
  int suma=0;
  for(int i=y; i<=y+dod; i++)
  {
    for(int j=x; j<=x+dod; j++)
    {
      suma++;
    }
  }
  return suma;
}

bool jest(bool tab[][size])
{
  for(int dod=1; dod<31; dod++)
  {
    for(int i=0; i+dod<size; i++)
    {
      for(int j=0; j+dod<size; j++)
      {
        if(tab[i][j]==true && tab[i][j+dod]==true && tab[i+dod][j]==true && tab[i+dod][j+dod]==true)
        {
          if(licz(tab, i, j, dod)==4)
          {
            cout << dod << " "  << i << " " << j << endl;
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main()
{
  dane info;
  info.N=maxa;

  ifstream plik("testdane.txt");
  int kol=0, wier=0, licz=0;
  string wart;
  while(plik >> wart)
  {
    if(wart=="1")
    {
      info.tab[licz].x=kol;
      info.tab[licz].y=wier;
      licz++;
      cout << licz;
      cout << info.tab[licz-1].x << ' ' << info.tab[licz-1].y << ' ' << endl;
    }
    kol++;
    if(kol==4)
    {
      kol=0;
      wier++;
    }
  }
  for(int i=0; i<maxa; i++)
  {
    tab[info.tab[i].y][info.tab[i].x]=true;
  }
  for(int i=0; i<31; i++)
  {
      for(int j=0; j<31; j++)
      {
        cout << tab[i][j] << " ";
      }
      cout << endl;
  }
  cout << jest(tab);
  
	return 0;
}
