#include <iostream>
#include <cmath>
using namespace std;

int power(int a, int b){
  int c=1;
  for (int i=0; i<b; i++) c*=a;
  return c;
}
int main(){
  int n, ic, nc, sum=0, nowa, pot;// n- wprowadzana liczba, ic, nc - kopie, sum-ilosc liczb podzielnych przez 7,
  cin >> n;
  for (int i=1; i<power(2, int(log10(n))+1); i++){
    ic=i;
    nc=n;
    nowa=0; //a- liczba zlozona z cyfr liczby n (kombincaje)
    pot=0; //j - ilosc jej cyfr
    while (ic>0){
      if (ic%2==1){
        nowa+=(nc%10)*power(10, pot);
        pot++;
      }
      nc/=10;
      ic/=2;
    }
    if (nowa%7==0){
      sum++;
      //cout << endl <<a;
    }
  }
  cout << sum;
  return 0;
}
