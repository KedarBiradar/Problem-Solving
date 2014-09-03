
#include <iostream>
#include <stdio.h>
#include <algorithm>

long long int stall[100002];
int C,N;

int check(int diff)
{
	int i,rem=1;
	long long int lastcow=stall[0];

	for(i=1;i<N;i++)
	{
		if(stall[i]-lastcow>=diff)
		{
			rem++;

			if(rem==C)
				return 1;

			lastcow=stall[i];
		}
	}
	return 0;
}

int main()
{

	int t;
	int i,low,high,diff;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&N,&C);

		for(i=0;i<N;i++)
			scanf("%lld",&stall[i]);

		std::sort(stall,stall+N);
		low=0;
		high=stall[N-1];
		while(low<high)
		{
			diff=(low+high)/2;
			if(check(diff)==1)
				low=diff+1;
			else
				high=diff;
		}		
		printf("%d\n",low-1);
	return 0;
	}
}

