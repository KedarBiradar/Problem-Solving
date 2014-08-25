#include <cstdio>

typedef long long int lli;
using namespace std;


int main()
{

	int tst;
	lli n,k,s,t,i,l,j,*A;
	scanf("%d",&tst);
	while(tst--)
	{
		scanf("%lld%lld%lld%lld",&s,&t,&n,&k);
		A= new lli[n+10];	
		A[0]=0;
		for(i=1;i<=n;i++)
		{
			s= (78901 + 31*s)%699037;
			t = (23456 + 64*t)%2097151;
			A[i]=A[i-1]+((s%100 + 1)*(t%100 + 1));
		}
	l=0;
	for(i=1;i<=n;i++)
	{
		if(A[i]<=k)
			l++;
		else 
			break;
	}
	if(l>0)
	{
		for(;i<=n;i++)
		{
			j=i-l;
			while(A[i]-A[j]>k)
				j++;
			l=i-j;
			if(l<=0)
			{
				printf("0\n");
				break;
			}
		}
		if(i>n)
		printf("%lld\n",l);

	}
	else
		printf("0\n");
	delete A;	
	}	
	return 0;
}
