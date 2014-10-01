#include <cstdio>

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int stars,d,flag=0;
	d=1;
	stars=(n/2);
	for(i=0;i<n;i++)
	{
		for(j=0;j<stars;j++)
		{
			printf("*");
		}
		for(j=0;j<d;j++)
		{
			printf("D");
		}
		for(j=0;j<stars;j++)
		{
			printf("*");
		}

		if(flag==0)
		{
			stars--;
			d+=2;
		}
		else
		{
			stars++;
			d-=2;
		}
		printf("\n");
		if(d==n)
			flag=1;
	}
	return 0;
}
