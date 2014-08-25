#include <cstdio>

int main()
{
	int t;
	long long k,n,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&k,&n);
		if(n==1)
		{
			printf("Male\n");
			continue;
		}
		else  if(n==2)
		{
			printf("Female\n");
			continue;			
		}
		else
		{
			count=0;
			n--;
			while(n>1)
			{
				if(n%2!=0)
					count++;
				n/=2;
			}
			if(count%2!=0)
				printf("Male\n");
			else
				printf("Female\n");
		}

	}
	return 0;
}
