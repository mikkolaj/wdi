#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
using namespace std;

const int maxa=100;

int findpos(int n, int tabl[], int od)
{
  for(int i=od; i<maxa*maxa; i++)
    if(n<=tabl[i] || (i>0 && tabl[i-1]>tabl[i]))
      return i;
}

int main()
{
  auto t1 = chrono::high_resolution_clock::now();
  int tab[maxa][maxa], wyn[maxa*maxa]={};
  srand(time(NULL));
  for(int i=0; i<maxa; i++)
    tab[i][0]=rand()%10+0;
  for(int i=0; i<maxa; i++)
    for(int j=1; j<maxa; j++)
    {
      tab[i][j]=tab[i][j-1]+rand()%10;
    } 
  /*for(int i=maxa-1; i>=0; i--)
  {
    for(int j=0; j<maxa; j++)
    {
      cout.width(4);
      cout << tab[i][j];
    }
    cout << endl;
  }*/
  for(int i=0; i<maxa; i++)
    wyn[i]=tab[0][i];
  int poz=maxa;
  int size = maxa;
  for(int i=1; i<maxa; i++)
  {
    int od=0;
    for(int j=0; j<maxa; j++)
    {
      od=findpos(tab[i][j], wyn, od);
      for(int k=size-1; k>=od; k--)
      {
        wyn[k+1]=wyn[k];
      }
      wyn[od]=tab[i][j];
      size++;
    }
  }
  auto t2 = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
 /* for(int i=0; i<maxa*maxa; i++)
    cout << wyn[i] << ' ';*/
  cout << "Czas trwania to: " << duration << " milisekund" << endl;
  return 0;
}
