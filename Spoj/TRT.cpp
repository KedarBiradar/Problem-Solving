#include <iostream>
#include <cstdio>

using namespace std;

typedef long long lli;

lli cost[2001][2001],cost1[2001][2001];
lli input[2001];
#define gc getchar_unlocked

void scanint(lli &x)
{
	register lli c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}


lli recursiveCall(int start,int end,int day)
{
	lli result;

	if(start==end)
	{
		cost1[end][day]=cost[start][day]=input[start]*day;
		return cost[start][day];
	}	
	else
	{
		if(cost[start][day]==0)
			cost[start][day]=input[start]*day+recursiveCall(start+1,end,day+1);

		if(cost1[end][day]==0)
			cost1[end][day]=input[end]*day+recursiveCall(start,end-1,day+1);

		result=max(cost[start][day],cost1[end][day]);
		return result;
	}
}


int main()
{

	lli n,i,j;
	scanint(n);
	for(i=0;i<n;i++)
		scanint(input[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cost1[i][j]=cost[i][j]=0;
		}
	}
	lli result=recursiveCall(0,n-1,1);
	printf("%lld\n",result);
	return 0;
}
