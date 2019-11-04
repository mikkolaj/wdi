#include <iostream>
using namespace std;

int dlug(float tab[])
{
  int licz=0, max=0, poz;
  float q;
  if(tab[0]==0 && tab[1]==0)
  {
    licz=2;
    max=2;
    for(int i=2; i<10; i++)
      if(tab[i-1]==tab[i])
      {
        licz++;
        if(licz>max)
          max=licz;
      }
      else
        break;
  }
  for(int i=0; i<10-1; i++)
    if(tab[i]!=0)
    {
      q=tab[i+1]/tab[i];
      licz=2;
      if(licz>max)
        max=2;
      poz=i;
      break;
    }

  for(int i=poz+1; i<10-1; i++)
  {

    if(tab[i]!=0 && tab[i+1]/tab[i]==q)
    {
      licz++;
      if(licz>max)
        max=licz;
    }
    else 
      if(tab[i]!=0)
      {
        q=tab[i+1]/tab[i];
        licz=2;
      }
      else 
        if(q==0)
        {
          if(tab[i+1]==0)
          {
            licz++;
            if(licz>max)
              max=licz;
          }
        }
    cout << q << " ";
  }
  return max;
}


int main()
{
  float tab[10]={0, 0, 0, 0, 1, 2, 4, 8, 16, 0};
  cout << endl << dlug(tab);
  return 0;
}
