#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int s5=0;
  int wynik=1;
  for(int k=5; k<=n; k*=5)
    s5+=n/k;   
  for(int i=2; i<=n; i++)
  {
    int ic=i;
    while(ic%5==0)
      ic/=5;
    while(ic%2==0 && s5>0)
    {
      ic/=2;
      s5--;
    }
    wynik=(wynik*ic)%1000000;
  }
  cout << "Ostatnia cyfra to: " << wynik << endl;
}
