#include <iostream>
#include <cmath>

using namespace std;
const int N = 4;

bool czypierwsza(int a)
{
  if(a<2)
    return false;
  else if(a==2)
    return true;
  else
  {
    for(int i=2; i*i<=a; i++)
    {
      if(a%i==0)
        return false;
    }
  }
  return true;
}

int dlug(int dane[][N])
{
  int r1, r2;
  int licz1=0, licz2=0, max=0;
  for(int i=0; i<N; i++)
  {
    r1=dane[i][1]-dane[i][0];
    r2=dane[1][i]-dane[0][i];
    licz1=licz2=1;
    for(int j=1; j<N; j++)
    {
      if(czypierwsza(dane[i][j]) && czypierwsza(dane[i][j-1]) && dane[i][j]-dane[i][j-1]==r1)
      {
        licz1++;
      }
      else
      {
        r1=dane[i][j]-dane[i][j-1];
        licz1=1;
      }
      if(czypierwsza(dane[j][i]) && czypierwsza(dane[j-1][i]) && dane[j][i]-dane[j-1][i]==r2)
      {
        licz2++;
      }
      else
      {
        r2=dane[j][i]-dane[j-1][i];
        licz2=1;
      }
      if(licz2>max)
        max=licz2;
      if(licz1>max)
        max=licz1;
    }
  }
  return max;
}

int main(){
  int tab[N][N];
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
      tab[i][j]=1;
  }
  tab[0][0]=3;
  tab[0][1]=5;
  tab[0][2]=7;
  tab[0][3]=9;
  cout << dlug(tab) << endl;
  return 0;
}
