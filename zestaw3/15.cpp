#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
  int licz=0;
  srand(time(NULL));
  const int idni=365;
  const int n=30;
  const int prob=10000;
  for(int z=0; z<prob; z++)
  {
  int dni[idni]={0};
  //for(int h=0; h<365; h++)
   // cout << dni[h] << " ";
  for(int i=0; i<n; i++)
  {
    int temp=rand()%idni;
    dni[temp]++;
    //cout << temp << endl;
  }
 // cout << endl;

  for(int i=0; i<idni; i++)
    if(dni[i]>1)
    {
      //cout << i << " jest" << endl << endl;
      licz++;
      break;
    }
  }
  cout << licz*1.0/prob << endl;
}
