#include <iostream>
#include <cmath>
using namespace std;

int ciaga(int n);
int ciagb(int n);

int main()
{
  int n, i=0;
  while(cin >> n && ciaga(i)==n)
  {
    cout << ciagb(i) << endl;
    i++;
  }
  return 0;
}

int ciaga(int n)
{
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  else
    return ciaga(n-1) - ciagb(n-1) * ciaga(n-2);
}

int ciagb(int n)
{
  if(n==0)
    return 2;
  else
    return ciagb(n-1) + 2 * ciaga(n-1);
}
