#include <iostream>
#include <cmath>
using namespace std;

int power(int a, int b){
    int c=1;
    for (int i=0; i<b; i++) c*=a;
    return c;
}
int main(){
    int n, xi, xn, s=0, a, j;// n- wprowadzana liczba, xi, xn- zmienne pomocnicze, s-ilosc liczb podzielnych przez 7,
    cin>>n;
    for (int i=1; i<power(2, (int)log10(n)+1); i++){
        xi=i;
        xn=n;
        a=0; //a- liczba zlozona z cyfr liczby n (kombincaje)
        j=0; //j - ilosc jej cyfr
        cout << i << endl << endl;
        while (xi>0){
            //cout << "Poczatek: xi " << xi << " xn " << xn << " a " << a << " j " << j << endl;
            if (xi%2==1){
                a+=(xn%10)*power(10, j);
                j++;
            }
            xn/=10;
            xi/=2;
            //cout << "Koniec:   xi " << xi << " xn " << xn << " a " << a << " j " << j << endl;
        }
        if (a%7==0){
            s++;
            //cout<<endl<<a;
        }
    }
    //cout<<endl<<endl<<s;
    return 0;
}
