/*

If you are travelling a lot you could have met the following problem: different countries use different measurement systems. Notably there are two major measurement systems for distances: metric and imperial. Metric system exploits kilometers while miles are used in the imperial system. It is known that one mile is approximately 1.609 kilometers. By interesting coincidence this is close enough to the value of the golden ration which is about 1.618. On this basis there is an interesting way of converting miles to kilometeres. Let's look into Fibonacci sequence: F1 = F2 = 1, Fn = Fn−1 + Fn−2, для n > 2. The ratio of two successive Fibonacci numbers Fn+1/Fn tends to golden ration as n tends to infinity. So you can partition the amount of miles you have into Fibonacci numbers, and you should use as large Fibonacci numbers as possible, then for each element in the partition you should go to the next Fibonacci number and sum up the elements again. That way you will get the approximate amount of kilometers. For example, 40 ⇒ 34 + 5 + 1 ⇒ 55 + 8 + 2 ⇒ 65. That means that 40 miles is approximately 65 kilometers (more precise value is 64,37 kilometers). Write a program that implements this method.
Input

The first line of input contains number t – the amount of test cases. The description of t test cases follows. Each test consists of a single integer m - the amount of miles.
Constraints

1 <= t <= 10000
1 <= m <= 10^15
Output

For each test case output the amount of kilometers calculated using the method given in the statement.
Example

Input:
4
1
7
40
128

Output:
2
11
65
207


*/


#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long lli;
using namespace std;

int main()
{
	int t,i;
	lli m;
	vector <lli> fibb;
	vector <lli>::iterator it;
	fibb.push_back(1);
	fibb.push_back(1);
	for(i=2;i<80;i++)
		fibb.push_back(fibb[i-2]+fibb[i-1]);

//	for(i=0;i<80;i++)
//		printf("%lld\n",fibb[i]);
		
	scanf("%d",&t);
	lli sum;
	while(t--)
	{
		sum=0;
		scanf("%lld",&m);
		while(m>0)
		{
				it=find(fibb.begin(),fibb.end(),m);

				if(it!=fibb.end())
					it++;
				else
					it=lower_bound(fibb.begin(),fibb.end(),m);

				if(*it==1)
				{
					sum+=2;
					m--;
				}
				else
				{
					sum+=*it;
					it--;
					m-=*it;
				}		
		}
		printf("%lld\n",sum);
	}

	return 0;

}
