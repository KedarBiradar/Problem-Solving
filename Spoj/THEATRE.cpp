#include <cstdio>
#include <stack>
typedef long long int lli;

using namespace std;

#define gc getchar_unlocked

void si(lli &x)
{
	register lli c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

lli arr[100010];

void sol(lli n)
{
	lli prod=1;
	lli mod=1000000007LL;
	stack<lli> s;
	s.push(arr[0]);
	lli element,next;
	for(lli i=1;i<n;i++)
	{
		next=arr[i];
		if(!s.empty())
		{
			element=s.top();
			s.pop();
			while(element<next)
			{
				prod=(prod*next)%mod;
				if(s.empty())
					break;
				element=s.top();
				s.pop();
			}
			if(element>next)
				s.push(element);
		}
		s.push(next);
	}
	printf("%lld\n",prod%mod);
}
int main()
{
	lli n;
	si(n);
	for(lli i=0;i<n;i++)
	{
		si(arr[i]);
	}
	sol(n);
	return 0;
}
