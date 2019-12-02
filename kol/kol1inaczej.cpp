#include <iostream>
using namespace std;

const int N=9;

int tnij(int tab[], int start, int suma, int ipodz)
{
  int sumaloc=0;
  for(int i=start; i<N; i++)
  {
    sumaloc+=tab[i];
    if(i==N-1)
    {
      if(sumaloc==suma && start!=0)
        return ipodz;
    }
    if(sumaloc==suma || start==0)
    {
      int temp=tnij(tab, i+1, sumaloc, ipodz+1);
      if(temp!=0)
        return temp;
    }
  }
  return 0;
}

int main()
{
  int tab[N]={1, 2, 3, 1, 5, 2, 2, 2, 6};
  cout << tnij(tab, 0, 0, 1) << endl;
  return 0;
}
