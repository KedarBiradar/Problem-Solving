#include <cstdio>

#define gc getchar_unlocked

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}


int min2(int a,int b)
{
	return a < b ? a : b;
}
int min3(int a,int b,int c)
{
	return min2(min2(a,b),c);
}

int min4(int a,int b,int c,int d)
{
	return min2(min2(a,b),min2(c,d));
}


int cost[100002][3];


int compute(int n)
{

	int i;

	cost[n-1][0]+=cost[n-1][1];
	cost[n-2][2]+=cost[n-1][1];

	cost[n-2][1]+=min3(cost[n-1][1],cost[n-1][0],cost[n-2][2]);
	cost[n-2][0]+=min3(cost[n-1][1],cost[n-1][0],cost[n-2][1]);

	
	for(i=n-3;i>=0;i--)
	{
		cost[i][2]+=min2(cost[i+1][1],cost[i+1][2]);
		cost[i][1]+=min4(cost[i+1][0],cost[i+1][1],cost[i+1][2],cost[i][2]);
		cost[i][0]+=min3(cost[i+1][0],cost[i+1][1],cost[i][1]);
	}
		return cost[0][1];
}

int main()
{

	int k,n,i,ret;
	for(k=1;;k++)
	{
		scanint(n);
		if(n==0)
			break;

		for(i=0;i<n;i++)
		{
			scanint(cost[i][0]);
			scanint(cost[i][1]);
			scanint(cost[i][2]);
		}

		ret=compute(n);
		printf("%d. %d\n",k,ret);

	}
	return 0;
}
