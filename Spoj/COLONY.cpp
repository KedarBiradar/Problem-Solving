#include <cstdio>
#include <cmath>
int main()
{
	long long k,n,count;

		scanf("%lld%lld",&k,&n);
		if(k==0)
		{
			printf("red\n");
			//continue;
		}
		else  if(k==1)
		{
			if(n==0)
				printf("blue\n");
			else
				printf("red\n");
			//continue;			
		}
		else
		{
			count=0;
			while(n>=1)
			{
				if(n%2!=0)
					count++;
				n/=2;
			}

			if(k%2==0)
			{
				if(count%2==0)
					printf("red\n");
				else
					printf("blue\n");
			}
			else
			{
				if(count%2==0)
					printf("blue\n");
				else
					printf("red\n");
			
			}
		}

	return 0;	

}
