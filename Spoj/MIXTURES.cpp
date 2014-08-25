#include <cstdio>
#include <limits.h>

using namespace std;

void mixture(int * arr,int n)
{
	long long cost[n+1][n+1],smoke[n+1][n+1];
	int i,j,k,l,q;
	for(i=0;i<n;i++)
	{
			cost[i][i]=arr[i];
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(j>i)			
				cost[i][j]=(cost[i][j-1]+arr[j])%100;

			if(i==j)
				smoke[i][j]=0;
			else if(j==i+1)
				smoke[i][j]=arr[i]*arr[j];
			else
				smoke[i][j]=-1;
		}


		for(i=0;i+1<=n-1;i++)
		{
				q=smoke[0][i]+smoke[i+1][n-1]+cost[0][i]*cost[i+1][n-1];//+(p[i-1]*p[k]*p[j]);
				if(q<smoke[0][n-1] || smoke[0][n-1]==-1)
				{
					smoke[0][n-1]=q;
				}
		}
	printf("%lld\n",smoke[0][n-1]);

	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=n;j++)
			printf("%lld\t",cost[i][j]);

	}

	printf("\nsmoke\n");
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=n;j++)
			printf("%lld\t",smoke[i][j]);

	}
}



int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		//printf("call mixture");
		mixture(arr,n);

	}


	return 0;
}
