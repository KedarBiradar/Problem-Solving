#include <stdio.h>

int main()
{
	
	long long int res,n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;

		res=(n*(n+1)*(2*n+1))/6;

		printf("%lld\n",res);
	}

	return 0;
}
