#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  const int max = 5;
  int tab[max][max]={};
  int liczba=0, x=0, y=0, od=0;
  for(int i=0; i<=max/2; i++)
  {
    while(x<max-1-od)
    {
      tab[y][x]=liczba;
      x++;
      liczba++;
    }
    while(y<max-1-od)
    {
      tab[y][x]=liczba;
      y++;
      liczba++;
    }
    while(x>=od)
    {
      tab[y][x]=liczba;
      x--;
      liczba++;
    }
    x++;
    y--;
    od++;
    while(y>od)
    {
      tab[y][x]=liczba;
      y--;
      liczba++;
    }
  }
  for(int i=max-1; i>=0; i--)
  {
    for(int j=0; j<max; j++)
    {
      cout.width(5);
      cout << tab[i][j];
    }
    cout << endl;
  }
}
