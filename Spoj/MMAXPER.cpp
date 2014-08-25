#include <cstdio>
#include <math.h>
#include <stdlib.h>
#define height 1
#define width 2
 
using namespace std;

#define gc getchar_unlocked

void si(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}
int rec[1010][2],dp[1010][2];

int max(int a,int b)
{
	return a>b?a:b;
}
int p(int i,int prev)
{
	if(dp[i][prev])
		return dp[i][prev];
	if(i==0)
	{
		dp[i][prev]=rec[i][prev];
		return rec[i][prev];
	}
	int tmp;
	tmp=max(p(i-1,0)+abs(rec[i-1][1]-rec[i][(prev+1)%2])+rec[i][prev],p(i-1,1)+abs(rec[i-1][0]-rec[i][(prev+1)%2])+rec[i][prev]);
	dp[i][prev]=tmp;
	return tmp;
}

int main()
{
	int n;
	si(n);
	for(int i=0;i<n;i++)
	{
		si(rec[i][0]);
		si(rec[i][1]);
	}

	int tmp=max(p(n-1,0),p(n-1,1));
	printf("%d\n",tmp);
	return 0;
}
