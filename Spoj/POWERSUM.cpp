#include <cstdio>
#include <math.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;

#define gc getchar_unlocked

void scanint(ll &x)
{
	register ll c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

void sol(ll sum,int n)
{
	int i;
	ll res=1;
	for(i=0;i<n-1;i++)
		res=((res%MOD)*2)%MOD;

	ll temp=(res*sum)%MOD;
	printf("%lld\n",temp);
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i;
		ll temp,sum=0;
		for(i=0;i<n;i++)
		{
			scanint(temp);
			sum=(sum+temp)%MOD;
		}
		sol(sum,n);
	}
	return 0;
}
