#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <iostream>
typedef long long ll;

using namespace std;

#define gc getchar_unlocked

void sl(ll &x)
{
	register ll c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}
int main()
{
	ll n,m,i,t;

	sl(t);
	int tst=1;

	while(t--)
	{
		sl(n);
		sl(m);
		vector<vector<int> >graph(n);
		ll t0,tm;
		ll indegree[n];

		for(i=0;i<n;i++)
			indegree[i]=0;
		for(i=0;i<m;i++)
		{
			sl(t0);
			sl(tm);
			graph[tm].push_back(t0);
			indegree[t0]++;
		}

		printf("Scenario #%d:\n",tst++);
		multiset< pair<ll,ll> > ss;
		for(i=0;i<n;i++)
			if(indegree[i]==0)
			{
				ss.insert(pair<ll,ll>(1,i));
			}

		while(!ss.empty())
		{
			multiset<pair<ll,ll> >::iterator i=ss.begin();
			int v=i->second;
			int r=i->first;
			ss.erase(ss.begin());
			printf("%d %d\n",r,v);		
			for(vector<int>::iterator it=graph[v].begin();it!=graph[v].end();it++)
			{
				indegree[*it]--;
				if(indegree[*it]==0)
				{
					ss.insert(pair<ll,ll>(r+1,*it));
				}
			}
		}
	}	
	return 0;
}
