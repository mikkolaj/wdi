#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
  int a, b;
  cin >> a >> b;
  vector<int> rozw;
  vector<int> liczby;
  cout << a/b << ".";
  a=a%b*10;
  bool okr=0;
  while(1){
    for(int i=0; i<rozw.size(); i++){
      if(a%b==rozw[i]){
        okr = 1;
        break;
      }
    }
    if(!okr){
      rozw.push_back(a%b);
      liczby.push_back(a/b);
      a=a%b*10;
    }
    else{
      rozw.push_back(a%b);
      liczby.push_back(a/b);
      break;
    }
  }
  bool byl=0;
  for(int i=0; i<liczby.size(); i++){
    //cout << liczby[i] << endl << pocz << endl << rozw[i] << endl << reszta << endl << !byl << endl;
    if(liczby[i]==liczby[liczby.size()-1] && rozw[i]==rozw[rozw.size()-1] && !byl)
    {
      cout << "(" << liczby[i];
      byl=1;
    }
    else if(liczby[i]==liczby[liczby.size()-1] && rozw[i]==rozw[rozw.size()-1] && byl)
      break;
    else
      cout << liczby[i];
  }
  cout << ")" << endl;
}

