#include <iostream>
using namespace std;

const int N=8;
int maxa=0;
int tab[N][N];

bool skacz(int ystart, int xstart, int suma)
{
  if(ystart>=N || xstart>=N || ystart<0 || xstart<0)
    return false;
  if(tab[ystart][xstart]!=0)
    return false;
  else
  {
    suma++;
    tab[ystart][xstart]=suma;
    if(suma==N*N)
    {
      for(int i=0; i<N; i++)
      {
        for(int j=0; j<N; j++)
        {
          cout.width(3);
          cout << tab[i][j];
        }
        cout << endl;
      }
      return true;
    }
  }  
  if(skacz(ystart+1, xstart+2, suma) || skacz(ystart+1, xstart-2, suma) ||
      skacz(ystart-1, xstart+2, suma) || skacz(ystart-1, xstart-2, suma) ||
      skacz(ystart+2, xstart+1, suma) || skacz(ystart+2, xstart-1, suma) ||
      skacz(ystart-2, xstart+1, suma) || skacz(ystart-2, xstart-1, suma))
  {
    return true;
  }
  else 
  {
    tab[ystart][xstart]=0;
    return false;
  }
}

int main()
{
  cout << skacz(3,3,0);
  return 0;
}
