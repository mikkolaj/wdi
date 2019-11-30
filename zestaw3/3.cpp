#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
  int n;
  cout << "Do jakiej wartosci szukac pierwszych?: ";
  cin >> n;
  vector<bool> tab;
  tab.resize(n);
  for(int i=2; i<=sqrt(n); i++)
  {
    if(!tab[i])
    {
      int ic=i;
      ic+=i;
      while(ic<=n)
      {
        tab[ic]=true;
        ic+=i;
      }
    }
  }
  cout << "Pierwsze: ";
  for(int i=2; i<tab.size(); i++)
    if(!tab[i])
      cout << i << endl;
  return 0;
}
