#include <iostream>
using namespace std;

const int N1=8;
const int N2=5;

int* powt(int tab1[], int tab2[])
{
  static int tab[N2]={};
  int licznik=0;
  for(int i=0; i<N1; i++)
  {
    int left=0, right=N2-1;
    while(left<=right)
    {
      int mid=(left+right)/2;
      if(tab2[mid]<tab1[i])
      {
        left=mid+1;
      }
      else if(tab2[mid]>tab1[i])
      {
        right=mid-1;
      }
      else if(tab2[mid]==tab1[i])
      {
        tab[licznik]=tab1[i];
        licznik++;
        break;
      }
    }
  }
  return tab;
}

int main()
{
  int tab1[N1]={1, 2, 5, 8, 101, 221, 454, 641};
  int tab2[N2]={2, 4, 6, 101, 200};
  static int* tab;
  tab=powt(tab1, tab2);
  for(int i=0; i<N2 && tab[i]!=0; i++)
    cout << tab[i] << endl;
  return 0;
}
