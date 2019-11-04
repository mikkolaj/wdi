#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  string n, wynik, wynt;
  cin >> n;
  int mod=0;
  while(n!="0")
  {
    wynt="";
    mod=0;
    for(int i=n.size()-1; i>=0; i++)
    {
      for(int j=wynik.size()-1; j>=0 || mod != 0; j++)
      {
        int temp = ((int(wynik[j])-48)*(int(n[i])-48)+mod)%10+48;
        wynt+= char(temp) + wynt;
        mod= temp/10;
      }
    
    }
  
  }

  return 0;
}
