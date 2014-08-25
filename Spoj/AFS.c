/*

Bhelu is the classmate of Bablu who made the Amazing Prime Sequence .

He felt jealous of his classmate and decides to make his own sequence. Since he was not very imaginative, he came up with almost the same definition just making a difference in f(n):

a[0] = a[1] = 0;

For n > 1, a[n] = a[n - 1] + f(n), where f(n) is the sum of natural numbers in the following set S.

S = {x | x < n and n % x = 0}

Now, Bablu asked him to make a code to find f(n) as he already had the code of his sequence. So, Bhelu asks for your help since he doesn't know Programming. Your task is very simple, just find a[n] for a given value of n(< 10^6).
Input

Your code will be checked for multiple Test Cases.

First Line of Input contains T (<= 100), the number of Test Cases.

Next T lines contain a single number N. (1 < N < 10^6).
Output

Single line containing a[n] i.e. nth number of the sequence for each test case.
Example

Input:
3

3

4

5

Output:
2

5

6

Explanation:

f(2) = 1 {1}

f(3) = 1 {1}

f(4) = 3 {1, 2}

f(5) = 1 {1}
*/

#include <stdio.h>

long long int arr[1000001];
long long int sieve[1000001];


void preCompute()
{
	long long int i,m,res;
	for(i=0;i<1000001;i++)
	{
		arr[i]=0;
		sieve[i]=1;
	}

	for(i=2;i<1000001;i++)
	{
		//if(sieve[i]==0)
		//{
		//	sieve[i]=i;
			m=i;
			res=m+m;
			while(res<1000001)
			{	
				//if(sieve[res]==0)
					sieve[res]+=i;
				res+=m;
			}
		//}

/*		if(i<=12)
			printf("%lld - %lld\n",i,sieve[i]);
*/	}

	arr[0]=arr[1]=0;

	for(i=2;i<1000001;i++)
	{
		arr[i]=arr[i-1]+sieve[i];
/*		if(i<=12)
			printf("%lld - %lld\n",i,arr[i]);
*/
	}
}

int main()
{	
	long int n,t;
//	calArr();
	preCompute();
	scanf("%ld",&t);
	while(t>0)
	{
		scanf("%ld",&n);
		printf("%lld\n",arr[n]);
		t--;
	}
	return 0;
}
