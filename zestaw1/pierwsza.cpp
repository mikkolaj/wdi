#include <iostream>
using namespace std;


int main()
{
  int num, licz=2;
  cin >> num;
  if(num < 2)
    cout << "nie";
  else if(num == 2)
    cout << "tak";
  else{
    while(licz*licz<=num)
    {
      if(num%licz == 0){
        cout << "nie";
        return 0;
      }
      licz++;
    }
    cout << "tak";
  }
  return 0;
}
