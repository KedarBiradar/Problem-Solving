#include<stdio.h>
int main()
{
long long int i,j,count=0;

for(i=2;i<1000000;i++)
{
	for(j=2;j<i;j++)
	{
		if(i%j==0)
			break;
	}
	if(i==j)
	{
		count++;
		//printf("%lld,",count);	
	}
}

	printf("\n%lld",count);
return 0;
}
