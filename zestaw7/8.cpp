#include <iostream>
#include <fstream>
using namespace std;

const int N=8;

int traverse(int tab[][N], int w, int k, int &mink, int suma, bool trasa[][N], bool trasatemp[][N])
{
  trasatemp[w][k]=true;
  if(w==7)
  {
    suma+=tab[w][k];
    if(suma<mink)
    {
      mink=suma;
      for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
          trasa[i][j]=trasatemp[i][j];
    }
    trasatemp[w][k]=false;
    return mink;
  }
  if(k-1>=0)
    traverse(tab, w+1, k-1, mink, suma+tab[w][k], trasa, trasatemp);
  traverse(tab, w+1, k, mink, suma+tab[w][k], trasa, trasatemp);
  if(k+1<8)
    traverse(tab, w+1, k+1, mink, suma+tab[w][k], trasa, trasatemp);
  trasatemp[w][k]=false;
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
	bool trasa[N][N]={};
	bool trasatemp[N][N]={};
	cout << endl << traverse(tab, 0, 5, mink, suma, trasa, trasatemp) << endl << endl;
	
	for(int i=7; i>=0; i--)
	{
    for(int j=0; j<8; j++)
    {
      cout.width(2);
      cout << trasa[i][j];
    }
    cout << endl;
  }
	return 0;
}
