#include <cstdio>
#include <limits.h>


int val[510],wt[510],m[100010];
int main()
{
	int t,F,E,n,W,tmp1,i,j;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d",&E,&F);
		W=F-E;
		scanf("%d",&n);
		int tmp=INT_MAX;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&val[i],&wt[i]);
			tmp=tmp<wt[i]?tmp:wt[i];
		}
		for(i=0;i<tmp;i++)
			m[i]=0;

		for(i=tmp;i<=W;i++)
		{
			tmp=INT_MAX;
			for(j=1;j<=n;j++)
			{
				tmp1=0;
				if(i>=wt[j])
				{
					if(m[i-wt[j]]>0 || i==wt[j])
						tmp1=val[j]+m[i-wt[j]];

					if(tmp1<tmp && tmp1 !=0 )
						tmp=tmp1;
				}
				if(tmp==INT_MAX)
					m[i]=0;
				else
					m[i]=tmp;

			}
		}
		if(m[W]==0)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",m[W]);

	}
	return 0;
}

