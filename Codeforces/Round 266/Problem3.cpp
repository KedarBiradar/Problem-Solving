#include <cstdio>
typedef long long ll;

ll arr[500020];
ll frq[500020];
int main()
{
	ll n,tmp;
	scanf("%lld",&n);
	
	arr[0]=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&tmp);
		arr[i]=arr[i-1]+tmp;
	}

	if(arr[n] % 3 != 0 )
	{
		printf("0\n");
		return 0;
	}

	ll x1=arr[n]/3;
	ll x2=arr[n]-x1;
	
	for(ll i=1;i<=n;i++)
		if(arr[i]==x1)
			frq[i]=frq[i-1]+1;
		else
			frq[i]=frq[i-1];
	ll count=0;
	for(ll i=n-1; i>1; i--)
	{
		if(arr[i]==x2)
			count+=frq[i-1];	
	}
	printf("%lld\n",count);
	return 0;
}
