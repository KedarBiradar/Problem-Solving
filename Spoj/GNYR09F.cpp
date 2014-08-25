
#include <cstdio>
#include <limits.h>

long long sol(int n,int k)
{
	int *row1,*row2,i,j;
	int *tmp;
	row1=new int[k+1];
	row2=new int[k+1];
	row1[0]=2;
	row1[1]=0;
	row2[0]=3;
	row2[1]=1;
	for(i=2;i<=k;i++)
		row1[i]=row2[i]=0;
	for(i=0;i<n-2;i++)
	{
		for(j=k;j>=1;j--)
		{
			row1[j]=row2[j]+row2[j-1]+row1[j]-row1[j-1];
		}
		row1[0]+=row2[0];

		tmp=row1;
		row1=row2;
		row2=tmp;
	}
	return row2[k];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int tst,n,k;
		scanf("%d%d%d",&tst,&n,&k);
		printf("%d %lld\n",tst,sol(n,k));
	}
	return 0;
}
