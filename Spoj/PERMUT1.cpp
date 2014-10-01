#include <cstdio>
#include <climits>

typedef long long ll;

ll dp[16][128];

void precompute()
{
	int i,j,k;
	for(i=1;i<128;i++)
		dp[0][i]=1;
	for(i=0;i<16;i++)
		dp[i][0]=1;

	for(i=1;i<16;i++)
	{
		for(j=1;j<128;j++)
		{
			ll sum=0;
			for(k=1;k<i && j-k>=0 ;k++)
				sum+=dp[i-1][k];
			dp[i][j]=sum;
		}
	}
}

ll sol(int n,int k)
{
	if(n==0)
		return 0;
	if(k==0)
		return 1;
	if(dp[n][k]!=-1)
		return dp[n][k];

	ll sum=0;
	for(int i=0;i<n && k-i>=0;i++)
		sum+=sol(n-1,k-i);
	dp[n][k]=sum;

	return dp[n][k];
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	//precompute();
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				dp[i][j]=-1;

		printf("%lld\n",sol(n,k));
	}
	return 0;
}
