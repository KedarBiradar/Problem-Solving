#include <cstdio>
#include <string.h>

long long arr[100],cost[100][100],smoke[100][100];

long long matrixChain(int start,int end)
{
	if(start==end)
		return 0;
	if(end==start+1)
		return arr[start]*arr[end];

	long long q;
	long long &min=smoke[start][end];
	if(min==-1)
	{
			for(int i=start;i+1<=end;++i)
			{
				q=cost[start][i]*cost[i+1][end]+matrixChain(start,i)+matrixChain(i+1,end);
				if(min==-1 || q < min)
					min=q;
			}
	}

	return min;

}

int main()
{
	int n,i,j;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			cost[i][i]=arr[i];
		}

		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				cost[i][j]=(cost[i][j-1]+arr[j])%100;

		 memset(smoke,-1,sizeof(smoke));

		printf("%lld\n",matrixChain(0,n-1));

	}

	return 0;
}
