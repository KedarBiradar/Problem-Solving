#include <iostream>
#include <algorithm>
#include <stdio.h>

int main()
{
	int t;
	long long int i,min,n,c,step;
	scanf("%d",&t);
	long long int stall[100002];
	while(t--)
	{
		scanf("%lld%lld",&n,&c);

		for(i=0;i<n;i++)
			scanf("%lld",&stall[i]);

		std::sort(stall,stall+n);

		step=((n-c)/(c-1))+1;
		min=stall[step]-stall[0];
		for(i=1;i<n-step;i++)
		{
			if(stall[i+step]-stall[i] < min )
				min=stall[i+step]-stall[i];
		}

		printf("%lld\n",min);

	}

}
