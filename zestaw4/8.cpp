#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 6;
int tab[MAX][MAX];

int lengthGeo(int tab[MAX][MAX], int MAX){
  int length = 2;
  int lengthMax = 2;

  for(int i = MAX - 3 ; i >= 0 ; i--){
    for(int j = 0 ; j < MAX - i - 1 ; j++){
      if(tab[i+1][j+1]*1.0 / tab[i][j] == tab[i+2][j+2]*1.0 / tab[i+1][j+1]){
        length++;
      }
      else{
        if(length > lengthMax){
          lengthMax = length;
          length = 2;
        }
      }
    
    }
    if(length > lengthMax){
      lengthMax = length;
    }
  }
  for(int j = 1 ; j <= MAX - 3 ; j++){
    for(int i = 0 ; i < MAX - j - 1 ; i++){
      if(tab[i+1][j+1]*1.0 / tab[i][j] == tab[i+2][j+2]*1.0 / tab[i+1][j+1]){
        length++;
      }
      else{
        if(length > lengthMax){
          lengthMax = length;
          length = 2;
        }
      }
    
    }
    if(length > lengthMax){
      lengthMax = length;
    }
  }
  if(lengthMax > 2) cout << "znaleziono" << endl;
  return lengthMax;
}

int main()
{
  srand(time(NULL));
  for(int i = 0 ; i < MAX ; i++){
    for(int j = 0 ; j < MAX ; j++){
      tab[i][j] = rand()%100+1;
    }
  }
  tab[2][0]=3;
  tab[3][1]=12;
  tab[4][2]=48;
  tab[5][3]=192;
  for(int i = 0; i < MAX; i++){
    for(int j = 0 ; j < MAX ; j++){
      cout.width(4);
      cout << tab[i][j];
    }
    cout << endl;
  }


  cout << lengthGeo(tab, MAX) << endl;
}
