#include<stdio.h>

void cal(int n)
{
	int i,x,y,maxx=0,maxy=0,tmp,flag=0;
	
		for(x=0;x*3<=n;x++)
		{
			tmp=n-(x*3);
			if(tmp%5==0)
			{
				maxx=x*3;
				maxy=tmp;
				flag=1;
			}
		}

	
//	printf("%d%d",maxx,maxy);
	if( maxx > 0 || maxy > 0 )
	{
		for(i=0;i<maxx;i++)
			printf("5");
		for(i=0;i<maxy;i++)
			printf("3");
		printf("\n");
	}
	else
		printf("-1\n"); 
}


int main()
{

	int t,n;
	scanf("%d",&t);

	while(t>0)
	{
		scanf("%d",&n);

		cal(n);
		t--;
/*
		if(n%5==0)
		{
			for(i=0;i<n;i++)
				printf("5");
			printf("\n");
		}
		else if(n%3==0)
		{

		}
		else
		{
			tmp=n%5;
			if(tmp%3==0)
			{
				
				for(i=0;i<n-3;i++)
					printf("5");
					printf("3");
					printf("3");
					printf("3");
				printf("\n");
			}
			else if(n%3==0)
			{
				for(i=0;i<n;i++)
					printf("5");
				printf("\n");
			}
		}
*/
	}

return 0;
}
