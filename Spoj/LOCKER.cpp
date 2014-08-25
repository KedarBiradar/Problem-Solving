#include <cstdio>

long long MP(long long n,long long k,long long mod)
{
	long long result=1;
	while(k>0)
	{
		if(k&1)
			result=(result*n)%mod;
		k>>=1;
		n=(n*n)%mod;
	}
	return result%mod;
}
int main()
{
	long long n,t;
	scanf("%lld",&t);
	while(t--)
	{

		scanf("%lld",&n);

		if(n<=4)
		{
			printf("%lld\n",n);
			continue;
		}
		int tmp=n%3;
		if(tmp==0)
		{
			printf("%lld\n",MP(3,n/3,1000000007)%1000000007);
		}
		else if(tmp==1)
		{
			printf("%lld\n",4*MP(3,(n-4)/3,1000000007)%1000000007);
		}
		else
		{
			printf("%lld\n",2*MP(3,(n-2)/3,1000000007)%1000000007);
		}
	}
	return 0;
}
