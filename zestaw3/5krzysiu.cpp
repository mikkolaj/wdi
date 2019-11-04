#include <iostream>
using namespace std;
int E[1100];
int T[1100];
int main ()
{
    int n;
    cin >> n;
    E[0]=1;
    T[0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<1100-1; j++)
        {
            T[j+1]+=(T[j]%i)*10;
            T[j]/=i;
        }
        T[1100-1]%=10;
        for (int j=0; j<1100; j++)
        {
            E[j]+=T[j];
        }
        for (int j=1100-1; j>=1; j--)
        {
            E[j-1]+=E[j]/10;
            E[j]%=10;
        }
    }
    cout << E[0] << ",";
    for (int i=1; i<1000; i++)
    {
        cout << E[i];
    }
    return 0;
}
