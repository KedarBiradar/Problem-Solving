#include <stdio.h>
#include <stdlib.h>

unsigned long long int rSquare(unsigned long long int a, unsigned long long int b, unsigned long long int c)
{
	unsigned long long int x=0, y=a%c;

	while(b>0)
	{
		if(b%2==1)
			 x=(x+y)%c;
		y=(y*2)%c;
		b=b/2;
	} 
	return x;
}


unsigned long long int mod(unsigned long long int a,unsigned long long int b,unsigned long long int c)
{
	unsigned long long int x = 1; 
	unsigned long long int y = a;
	while (b>0)
	{
		 if (b%2==1) 
			x = rSquare(x,y,c);
		 y = rSquare(y,y,c); 
 		 b = b/2;
	}
	return x;
}

void fermats(unsigned long long int p)
{

	unsigned long long int a,x,y;
	int i;
	for(i=0;i<10;i++)
	{
		a=rand()%(p-1)+1;
		//x=rSquare(a,p-1,p);
		y=mod(a,p-1,p);
		if(y!=1)
		{
			printf("NO\n");
			break;
		}

	}
	if(i==10)
		printf("YES\n");
}

int main()
{

	int t;
	unsigned long long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		fermats(n);
	}
	return 0;
}
