#include <stdio.h>

int main()
{
	int t,n,diff,i;
	scanf("%d",&t);
	long long int n3,n3n,sum,start;
	while(t>0)
	{
		scanf("%lld%lld%lld",&n3,&n3n,&sum);
		n=(2*sum)/(n3+n3n);
		diff=(sum-(n*n3))/(((n*(n-1))/2)-(2*n));
		//diff=(n3n-n3)/(n-5);		
		//printf("%d-%d\n",n,diff);
		start=n3-(2*diff);
		printf("%d\n",n);
		for(i=0;i<n;i++)
		{
			printf("%lld ",start);
			start+=diff;
		}	
		//printf("\n");	
		t--;
	}
	return 0;
}