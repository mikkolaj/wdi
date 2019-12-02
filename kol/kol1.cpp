#include <iostream>
using namespace std;

const int N=3;

int tnij(int tab[], int start, int suma, int ipodz, int &maxip)
{
  int sumaloc=0;
  for(int i=start; i<N; i++)
  {
    sumaloc+=tab[i];
    if(i==N-1)
    {
      if(sumaloc==suma && start!=0)
      {
        if(ipodz>maxip)
          maxip=ipodz;
      }
    }
    if(sumaloc==suma || start==0)
      tnij(tab, i+1, sumaloc, ipodz+1, maxip);
  }
  return maxip;
}

int main()
{
  int tab[N]={1,8,12};
  int maxp=0;
  cout << tnij(tab, 0, 0, 1, maxp) << endl;
  return 0;
}
