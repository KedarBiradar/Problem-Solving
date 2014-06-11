#include<stdio.h>
int main()
{

long long int i,j,count=1;
for(i=3;i<31630;i++)
{
	for(j=2;j<i;j++)
	{
		if(i%j==0)
			break;
	}
	if(i==j)
	{
		printf("%lld,",i);
		count++;	
	}
}

	printf("\n%lld",count);
return 0;
}
