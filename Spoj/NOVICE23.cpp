#include <cstdio>
#include <stdlib.h>

long long count[1000010];
bool sieve[1000001];

void precompute()
{
	long long i,j,l;

	for(i=0;i<=1000000;i++)
		sieve[i]=true;

	for(i=2;i<=1000;i++)
	{
		l=i*i;
		for(j=l;j<=1000000;j+=i)
		{
			sieve[j]=false;
		}
	}
	count[0]=count[1]=0;
	count[2]=1;

	for(i=3;i<=1000000;i++)
		if(sieve[i])
			count[i]=count[i-1]+1;
		else
			count[i]=count[i-1];
}
int main()
{
	int t;
	long long n;
	precompute();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",count[n]);
	}
	return 0;
}

/*
Input: an integer n > 1
 
Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding √n:
  if A[i] is true:
    for j = i2, i2+i, i2+2i, ..., not exceeding n :
      A[j] := false
 
Output: all i such that A[i] is true. */
