#include <iostream>
using namespace std;

int dlug(int tab[])
{
  int licz=2, max=0, r;
  r=tab[1]-tab[0];
  for(int i=1; i<10-1; i++)
  {
    if(tab[i+1]-tab[i]==r)
    {
      licz++;
      if(licz>max)
        max=licz;
    }
    else
    {
      r=tab[i+1]-tab[i];
      licz=2;
    }
  }
  return max;
}


int main()
{
  int tab[10]={1, 2, 3, -7, -6, 543, 0, 0, 0, 0};
  cout << dlug(tab);
  return 0;
}
