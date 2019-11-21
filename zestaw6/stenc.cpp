#include <iostream>
#include<cmath>
using namespace std;

const int N=7;



bool czy_pierwsza(int x){
  for(int i=2; i< sqrt(x); i++) if(x%i==0) return false;
  return true;
}

int waga_liczby(int k){
  int a=0;
  int licznik=0;
  int b=k;
  for(int i=2; i<=b; i++){
    if(czy_pierwsza(i) && k%i==0){
      k/=i;
      if(i!=a) licznik++; a=i;

      i--;
    }

  }
  return licznik;
}

bool waga (int tab[N], int p=-1, int wagaG1=0, int wagaG2=0, int wagaG3=0){
  if((wagaG1==wagaG2==wagaG3) && p>=N-1) return true;
  if((wagaG1!=wagaG2 || wagaG1!=wagaG3 || wagaG2!=wagaG3) && p>=N-1) return false;
  return ((tab[N], p+1, wagaG1+waga_liczby(tab[p+1]), wagaG2, wagaG3) || (tab[N], p+1, wagaG1, wagaG2+waga_liczby(tab[p+1]), wagaG3)|| (tab[N], p+1, wagaG1, wagaG2, wagaG3+waga_liczby(tab[p+1])));
}


int main()
{
  int tab[N]={30, 14, 2, 2, 3, 5};
  cout << waga_liczby(13);


  return 0;
}
