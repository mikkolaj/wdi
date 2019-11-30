#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  int num;
  cin >> num;
  int p = sqrt(num);
  while(p>0)
  {
    if(num/p*p==num)
    {
      cout << num/p << endl << p << endl;
      return 0;
    }

    p--;
  }	
  return 0;
}
