#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int tab[5]={0};
  int k, i=0;
  while(cin >> k && k!=0)
  {
    tab[i]=k;
    /*for(int h=0; h<5; h++)
    {
      cout << tab[h] << " ";
    }
    cout << endl;*/
    if(i==4)
    {
      if((tab[0]+tab[1]+tab[3]+tab[4])/4.0==tab[2])
        cout << "Srednia jest: " << tab[2] << endl;
      for(int s=1; s<5; s++)
      {
        tab[s-1]=tab[s];
      }
      i--;
    }
    i++;
  }
  
}
