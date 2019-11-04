#include <iostream>
using namespace std;


int main()
{
	int fib1=1, prev1=0, sum1=0;
	int fib2=1, prev2=0, sum2=0;
	int sum;
	cin >> sum;
	sum+=1;
	while(1)
	{
		while(1)
		{
			sum1+=fib1;
			int dif = sum1-sum2;	
			while(dif>sum)
			{
				dif-=fib2;
				if(dif==sum)
					break;
				if(dif<sum)
				{
					cout << sum << " Nie jest" << endl;
					return 0;
				}
				int temp2=prev2;
				prev2=fib2;
				fib2+=temp2;
			}
			if(dif==sum)
				break;
			int temp=prev1;
			prev1=fib1;
			fib1+=temp;
		}
		sum++;
		fib1=1, prev1=0, sum1=0;
		fib2=1, prev2=0, sum2=0;
	}
	return 0;
}
