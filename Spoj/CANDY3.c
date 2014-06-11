#include <stdio.h>

int main()
{
	long long int t,n,sum,i,c;

	scanf("%lld",&t);
	while(t--)
	{
		//printf("\n");
		sum=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&c);
			sum+=c;
			if(sum>=n)
				sum%=n;
		}
		if(sum==0)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
