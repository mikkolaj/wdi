#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

const int maxa = 100;

int main()
{ 
  int tab[maxa][maxa];
  int tab2[maxa*maxa];
  int licz=0;
  auto t1 = chrono::high_resolution_clock::now();
  srand(time(NULL));
  for(int i=0; i<maxa; i++)
    tab[i][0]=rand()%10+0;
  for(int i=0; i<maxa; i++)
    for(int j=1; j<maxa; j++)
    {
      tab[i][j]=tab[i][j-1]+rand()%10;
    } 


  for(int i=0; i<maxa; i++)
  {
    for(int j=0; j<maxa; j++)
    {
      tab2[licz]=tab[i][j];
      licz++;
    }
  }
  for(int i=0; i<maxa*maxa; i++)
  {
    for(int j=0; j<maxa*maxa-1; j++)
    {
      if(tab2[j+1]<tab2[j])
      {
        int temp=tab2[j+1];
        tab2[j+1]=tab2[j];
        tab2[j]=temp;
      }
    }
  }
  auto t2 = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
  cout << "Czas trwania to: " << duration << " milisekund" << endl;
}
