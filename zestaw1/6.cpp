#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double left=0, right=5, mid, eq=1;
	while(abs(eq-2019)>=0.1)
	{
		mid=(left+right)/2;
		eq=pow(mid, mid);
		if(eq > 2019)
			right = mid;
		else
			left = mid;
	}
	cout << mid << endl;
	return 0;
}

