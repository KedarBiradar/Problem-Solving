#include <cstdio>
#include <iostream>

int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n,W,i,j;
	int K[501][101],S[501][101],Wt[101],val[101];
	while(1)
	{
		scanf("%d%d",&W,&n);
		if(W==0 && n==0)
			break;
		
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&Wt[i],&val[i]);
		}

		for(i=0;i<=n;i++)
			S[0][i]=K[0][i]=0;

		for(i=0;i<=W;i++)
			S[i][0]=K[i][0]=0;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=W;j++)
			{
				if(Wt[i-1]>j)
				{
					K[j][i]=K[j][i-1];
					S[j][i]=S[j][i-1];
				}
				else
				{
					if(K[j][i-1]>K[j-Wt[i-1]][i-1]+val[i-1])
					{
						K[j][i]=K[j][i-1];
						S[j][i]=S[j][i-1];
					}		
					else if(K[j][i-1]==K[j-Wt[i-1]][i-1]+val[i-1])
					{
						K[j][i]=K[j-Wt[i-1]][i-1]+val[i-1];
						S[j][i]=min(S[j-Wt[i-1]][i-1]+Wt[i-1],S[j][i-1]);
					}			
					else
					{
						K[j][i]=K[j-Wt[i-1]][i-1]+val[i-1];
						S[j][i]=S[j-Wt[i-1]][i-1]+Wt[i-1];
					}		

				}
			}
		}
		printf("%d %d\n",S[W][n],K[W][n]);
	}
}
