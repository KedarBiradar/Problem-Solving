#include <cstdio>

int main()
{
	int t;
	scanf("%d",&t);
	long int x,y;
	while(t--)
	{
		scanf("%ld%ld",&x,&y);
	
		if(x==y || x-2==y)
		{
			if(x%2==0)
				printf("%ld\n",x+y);
			else
				printf("%ld\n",x+y-1);
		}
		else
		{
			printf("No Number\n");

		}

	}

	return 0;
}
