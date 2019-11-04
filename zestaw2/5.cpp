#include <iostream>
using namespace std;

int main()
{
  int num;
  cin >> num;
  long int sil=1;
  for(int i=1; i<=num; i++)
  {
    sil = sil*i%1000000;
    while(sil%10==0)
      sil/=10;
  }
  cout << "Ostatnia cyfra to: " << sil%10 << endl;
}
