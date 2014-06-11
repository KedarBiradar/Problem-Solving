#include <stdio.h>

int main()
{
	int t,n,a,b,aa,bb,steps=1,i;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d%d",&n,&aa,&bb);
		/*for(i=n-1;i>=0;i--)
		{
			printf("%d ",(i*a)+((n-i-1)*b));
		}*/

		if(aa>bb)
		{
			a=aa;
			b=bb;
		}		
		else
		{
			a=bb;
			b=aa;
		}
		
		if(a==b)
		{
			printf("%d",(n-1)*a);
		}
		else
		{
			for(i=0;i<n;i++)
			{
				printf("%d ",(i*a)+((n-i-1)*b));
			}
		}
		printf("\n");
		t--;
	}
	return 0;
}
