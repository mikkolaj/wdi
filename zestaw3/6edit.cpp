#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n, min, imin;
  int tab[10];
  for(int i=0; i<10; i++)
    cin >> tab[i];
  while(cin >> n && n!=0)
  { 
    min = tab[0];
    imin = 0;
    for(int i=0; i<10; i++)
      if(tab[i]<min)
      {
        min = tab[i];
        imin = i;
      }
    if(n>min)
      tab[imin] = n;
  }
  cout << "10 co do wielkosci liczba to: " <<  endl;
  min = tab[0];
  for(int i=1; i<10; i++)
    if(tab[i]<min)
      min = tab[i];
  cout << min << endl;
  return 0;
}
