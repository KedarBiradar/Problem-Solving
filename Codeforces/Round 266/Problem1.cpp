#include <cstdio>

long long minn(long long a,long long b)
{
	return a<b?a:b;
}
int main()
{
	long long n,m,a,b;
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	if(n<m)
	{
		printf("%lld\n",minn(n*a,b));
		return 0;
	}
	/*if( (m*a) <= b )
	{
		printf("%lld\n",n*a);
	}
	else
	{*/
		int rem=n%m;
		printf("%lld\n",minn(((n/m)+1)*b,minn(((n/m)*b)+(rem*a),(n*a))));
	//}
	return 0;
}
