#include <stdio.h>

long long int series[12]={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};

int main()
{
	long long int i,t,n,count;

	scanf("%lld",&t);
	while(t--)
	{

		scanf("%lld",&n);
		count=0;
		for(i=0;i<12;i++)
		{
			if(n>=series[i])
				count=count+(n/series[i]);
		}
		printf("%lld\n",count);
	}

	/*for(i=5;i<1000000001;i*=5)
		printf("%lld,",i);
	*/
	return 0;
}
