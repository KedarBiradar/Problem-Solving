#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

ll arr[100001];

#define gc getchar_unlocked

void si(ll &x)
{
	register ll c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}


struct tuple
{
	ll height;
	int index;
	tuple(ll _h,int _i): height(_h), index(_i) {}
};

ll area(int n)
{
	stack<tuple> stk;
	int left;
	ll max=-1,local;
	for(int i=0;i<=n;i++)
	{
		while(!stk.empty() && (i==n || stk.top().height> arr[i]))
		{
			if(stk.size()>1)
			{
				tuple t=stk.top();
				stk.pop();
				left=stk.top().index;
				stk.push(t);
			}
			else
			{
				left=-1;
			}
			local=(i-left-1)*stk.top().height;
			stk.pop();

			if(local>max)
				max=local;
		}
		if(i<n)
		{
			stk.push(tuple(arr[i],i));
		}
	}
	return max;
}
int main()
{
	int n;
	while(true)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			si(arr[i]);

		printf("%lld\n",area(n));	
	}
	return 0;
}
