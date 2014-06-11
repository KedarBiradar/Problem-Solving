#include<stdio.h>

int main()
{
	long long int sieve[101];
	int i,j;
	for(i=0;i<101;i++)
		sieve[i]=1;

	sieve[0]=sieve[1]=1;
	for(i=1;i<101;i++)
	{
		for(j=i;j<101;j++)
			sieve[j]*=i;
	}
	for(i=0;i<101;i++)
		printf("%d-%lld\n",i,sieve[i]);

return 0;
}
