#include <cstdio>
#include <algorithm>

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

int YSUM[512][512],BSUM[512][512],DP[512][512];

int max(int a,int b)
{
	return a>b?a:b;
}
int solution(int n,int m)
{
	int i,j;
	for(i=0;i<=n;i++)
		DP[i][0]=0;
	for(j=0;j<=m;j++)
		DP[0][j]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			DP[i][j]=max(DP[i][j-1]+BSUM[i-1][j-1],DP[i-1][j]+YSUM[i-1][j-1]);
		}
	}
	return DP[n][m];
}
int main()
{
	int n,m;
	while(true)
	{
		int i,j,num;
		si(n);
		si(m);
		if(n==0 && m==0)
			break;

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				si(num);
					if(j==0)
						YSUM[i][j]=num;
					else
						YSUM[i][j]=YSUM[i][j-1]+num;
			}
		}

		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				si(num);
					if(i==0)
						BSUM[i][j]=num;
					else
						BSUM[i][j]=BSUM[i-1][j]+num;
			}
		}
		printf("%d\n",solution(n,m));
	}

	return 0;
}
