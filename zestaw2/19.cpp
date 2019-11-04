#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  for(int i=1; i<=100; i++)
  {
    for(int j=i; j<=100; j++)
    {
      if(sqrt(i*i+j*j)-int(sqrt(i*i+j*j))==0)
        cout << i << " x " << j << " x " << sqrt(i*i+j*j) << endl;
    }
  }
}
