#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  int tab[10];
  for(int i=0; i<10; i++)
    cin >> tab[i];
  for(int i=0; i<10; i++)
    for(int j=0; j<9; j++)
      if(tab[j+1]>tab[j])
      {
        int temp;
        temp=tab[j];
        tab[j]=tab[j+1];
        tab[j+1]=temp;
      }
  while(cin >> n && n!=0)
  {   
    if(n>tab[9])
    {
      int shift, temp;
      for(int i=0; i<10; i++)
        if(n>tab[i])
        {
          shift = tab[i];
          tab[i] = n;
          n = shift;
        }
    }
  }
  cout << "10 co do wielkosci liczba to: " << tab[9] << endl;
  return 0;
}
