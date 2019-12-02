#include <iostream>
using namespace std;

int main()
{
  int frac[1100]={0}, sum[1100]={0}, n;
  cin >> n;
  frac[0]=1;
  sum[0]=1;
  for(int i=1; i<=n; i++)
  {
    for(int j=0; j<1100-1; j++)
    {
      frac[j+1]+=(frac[j]%i)*10;
      frac[j]/=i;
    }
    frac[1100-1]%=10;
    for(int j=0; j<1100; j++)
      sum[j]+=frac[j];
    for(int j=1100-1; j>=1; j--)
    {
      sum[j-1]+=sum[j]/10;
      sum[j]%=10;
    }

  }
  cout << sum[0] << ",";
  for(int i=1; i<1000; i++)
    cout << sum[i];
  return 0;
}
