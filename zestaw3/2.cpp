#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int tab1[10]={0};
  int num1, num2;
  cout << "Podaj 2 liczby: ";
  cin >> num1 >> num2;
  if(int(log10(num1))==int(log10(num2)))
  {
  while(num1 != 0)
  {
    tab1[num1%10]++;
    tab1[num2%10]--;
    num1/=10;
    num2/=10;
  }
  for(int i=0; i<10; i++)
  {
    if(tab1[i]!= 0)
    {
      cout << "Nie sa" << endl;
      return 0;
    }
  }
  cout << "Sa" << endl;
  return 0;
  }
  else
    cout << "Nie sa" << endl;
  return 0;
}
