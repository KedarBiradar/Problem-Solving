/*
//recursive solution
#include <cstdio>

int arr[32][32];
bool visited[32];
long long count;

void recursion(int start,int n)
{
	int j;
	if(start==n-1)
	{
		for(j=0;j<n;j++)
		{
			if(!visited[j] && arr[start][j])
				count++;
		}
	}
	else
	{
		for(j=0;j<n;j++)
		{
			if(!visited[j] && arr[start][j])
			{
				visited[j]=true;
				recursion(start+1,n);
				visited[j]=false;
			}
		}
	}
}
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);
			
		count=0;
		for(i=0;i<=n;i++)
			visited[i]=false;
		recursion(0,n);
		printf("%lld\n",count);		
	}
	return 0;
}*/

#include <cstdio>
#include <string.h>

long long dp[1048576];
int arr[21][21];

int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));

		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);

		dp[(1<<n)-1]=1;

		for(int mask=(1<<n)-1;mask>=0;mask--)
		{
			int k=0;
			for(int l=mask;l>0;l/=2)
				k+=(l&1);

			for(j=0;j<n;j++)
			{
				if(arr[k][j]==1 && (mask&(1<<j))==0)
					dp[mask]+=dp[mask | (1<<j)];
			}
			
		}
		printf("%lld\n",dp[0]);
	}
	return 0;
}
