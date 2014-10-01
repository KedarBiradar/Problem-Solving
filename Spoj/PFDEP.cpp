#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
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
	ll n,m,i;
	sl(n);
	sl(m);
	vector<vector<int> >graph(n);
	ll t0,k,tm;
	ll indegree[n];
	for(i=0;i<n;i++)
		indegree[i]=0;
	for(i=0;i<m;i++)
	{
		sl(t0);
		sl(k);
		for(ll j=0;j<k;j++)
		{
			sl(tm);
			graph[tm-1].push_back(t0-1);
			indegree[t0-1]++;
		}
	}
	set<int> s;
	for(i=0;i<n;i++)
		if(indegree[i]==0)
			s.insert(i);

	while(!s.empty())
	{
		int v=*s.begin();
		s.erase(s.begin());
		printf("%d ",v+1);
		for(vector<int>::iterator it=graph[v].begin();it!=graph[v].end();it++)
		{
			indegree[*it]--;
			if(indegree[*it]==0)
				s.insert(*it);
		}
	}
	printf("\n");
	
	return 0;
}
