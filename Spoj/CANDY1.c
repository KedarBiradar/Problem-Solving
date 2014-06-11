#include <stdio.h>

int main()
{
	int n,arr[10001],i;
	long int sum,avg,moves;
	scanf("%d",&n);

	while(n!=-1)
	{

		sum=0;
		moves=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}

		if(sum%n==0)
		{
			avg=sum/n;
			for(i=0;i<n;i++)
			{
				if(avg>arr[i])
				{
					moves+=avg-arr[i];
				}
			}

			printf("%ld\n",moves);
		}
		else
			printf("-1\n");

		scanf("%d",&n);
	}
	return 0;
}
