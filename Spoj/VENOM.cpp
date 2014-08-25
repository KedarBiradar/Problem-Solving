#include <cstdio>
#include <math.h>
typedef long long lli;
int main()
{
	lli t,h,p,a;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&h,&p,&a);
		if(h<=p)
		{
			printf("1\n");
			continue;
		}		
		double y,z,d;
		lli count=0;
		y=p-2*a;
		z=2*(a-h);
		d=sqrt(y*y-4*p*z);
		count=ceil((-1*y + d)/(2*p));
		count=count+(count-1);
		printf("%lld\n",count);
	}
	
}
