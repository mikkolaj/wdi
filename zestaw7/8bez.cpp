#include <iostream>
#include <fstream>
using namespace std;

const int N=8;

int traverse(int tab[][N], int w, int k, int &mink, int suma)
{
  if(w==N-1)
  {
    suma+=tab[w][k];
    if(suma<mink)
      mink=suma;
  }
  if(w<N-1)
  {
    if(k-1>=0)
      traverse(tab, w+1, k-1, mink, suma+tab[w][k]);
    traverse(tab, w+1, k, mink, suma+tab[w][k]);
    if(k+1<8)
      traverse(tab, w+1, k+1, mink, suma+tab[w][k]);
  }
  return mink;
}

int main()
{
  int tab[N][N]={};
  int a;
  ifstream dane("dane.txt");
  for(int i=7; i>=0; i--)
    for(int j=0; j<8; j++)
      dane >> tab[i][j];
  for(int i=7; i>=0; i--)
  {
    for(int j=0; j<8; j++)
    {
      cout.width(2);
      cout << tab[i][j]; 
    }
    cout << endl;
  }
  int suma=0;
  int mink = 10000000;
  cout << endl << traverse(tab, 0, 5, mink, suma) << endl;
  return 0;
}
