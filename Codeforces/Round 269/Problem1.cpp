#include <cstdio>

int main()
{
	int n,i;
	int count[10];
	for(i=0;i<10;i++)
	{
		count[i]=0;
	}
	
	for(i=0;i<6;i++)
	{
		scanf("%d",&n);
		count[n]++;
	}
	bool legs=false,e=false,b=false;
	for(i=0;i<10;i++)
	{

		if(count[i]>=4)
		{
			legs=true;
			count[i]-=4;
		}
		if(count[i]==2)
			e=true;
		if(count[i]==1)
			b=true;
	}
	if(legs&&e)
		printf("Elephant\n");
	else if(legs&&b)
		printf("Bear\n");
	else
		printf("Alien\n");
	return 0;
}
