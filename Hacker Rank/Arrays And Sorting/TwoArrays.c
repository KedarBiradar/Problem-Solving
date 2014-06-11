#include <stdio.h>
#include <algorithm>
int main()
{
	int t,n,i;
	long long int k,min1=1000000001,min2=1000000001,ai[1001],bi[1001];

	scanf("%d",&t);

	while(t>0)
	{
		scanf("%d%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&ai[i]);
				//if(ai<min1)
				//	min1=ai;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&bi[i]);
				//if(bi<min2)
				//	min2=bi;
		}

/*
		if(min1+min2>=k)
			printf("YES\n");
		else
			printf("NO\n");
*/
		t--;
	}
	return 0;
}
