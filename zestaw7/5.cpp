#include <iostream>
using namespace std;

const int N=8;
int maxa=0;
bool tab[N][N];
int wyn[N*N][2];

bool skacz(int ystart, int xstart, int suma)
{
  if(ystart>=N || xstart>=N || ystart<0 || xstart<0)
    return false;
  if(tab[ystart][xstart])
    return false;
  else
  {
    tab[ystart][xstart]=true;
    suma++;
    wyn[suma-1][0]=ystart;
    wyn[suma-1][1]=xstart;
    if(suma==N*N)
    {
      for(int i=0; i<N*N; i++)
      {
        cout << wyn[i][0] << " " << wyn[i][1] << endl;
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
    tab[ystart][xstart]=false;
    return false;
  }
}

int main()
{
	cout << skacz(3,3,0);
	return 0;
}
