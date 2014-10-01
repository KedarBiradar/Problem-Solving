#include <cstdio>
#include <limits.h>

#define si(n) scanf("%d",&n)
#define pfn(n) printf("%d\n",n)
#define FOR(i,a,n) for(i=a;i<n;i++)

using namespace std;

long long count[100010];
long long dp[100010];
int main()
{
	long long n,tmp,i;
	scanf("%lld",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%lld",&tmp);
		count[tmp]++;
	}
	dp[0]=0;
	dp[1]=count[1];
	for(i=2;i<=100000;i++)
	{
		if(dp[i-1]<(dp[i-2]+(count[i]*i)))
			dp[i]=dp[i-2]+(count[i]*i);
		else
			dp[i]=dp[i-1];
	}
	printf("%lld\n",dp[100000]);
	return 0;
}
