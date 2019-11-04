#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  int num;
  cin >> num;
  for(int i=2; i<=5; i++)
    while(num/i*i==num)
      num/=i;
  if(num==1)
    cout << "jest" << endl;
  else
    cout << "nie jest" << endl;
  return 0;
}
