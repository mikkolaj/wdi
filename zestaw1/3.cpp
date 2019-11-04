#include <iostream>
using namespace std;


int main()
{
	int fib1=1, prev1=0, sum1=0;
	int fib2=1, prev2=0, sum2=0;
	int sum;
	cin >> sum;
	while(1)
	{
		sum1+=fib1;
		int dif = sum1-sum2;
		cout << dif<< endl;
		if(dif==sum)
		{
			cout << "Jest";
			return 0;
		}
		while(dif>sum)
		{
			dif-=fib2;
					cout << dif<< endl;
			if(dif==sum)
			{
				cout << "Jest";
				return 0;
			}
			if(dif<sum)
			{
				cout << "Nie jest";
				return 0;
			}
			int temp2=prev2;
			prev2=fib2;
			fib2+=temp2;
		}	
		int temp=prev1;
		prev1=fib1;
		fib1+=temp;
	}
	return 0;
}
