#include<stdio.h>

using namespace std;

int main()
{

	int t,n,i,rindex,Rindex;
	long int r,R,maxOuter,maxInner,maxOuter2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxInner=0;
		maxOuter2=maxOuter=0;
		Rindex=rindex=-1;
		for(i=0;i<n;i++)
		{
			scanf("%ld%ld",&r,&R);
			if(maxInner<r)
			{
				maxInner=r;
				rindex=i;
			}	
			if(maxOuter<R)
			{
				maxOuter2=maxOuter;

				maxOuter=R;
				Rindex=i;
			}
			else if(R<=maxOuter && R > maxOuter2)
			{
				maxOuter2=R;
			}
		}
//		printf("%ld\t%ld\t%ld\t%d\t%d\n",maxInner,maxOuter,maxOuter2,rindex,Rindex);
		if(rindex!=Rindex)
		{
			if(maxInner>maxOuter)
				printf("%d\n",rindex+1);
			else
				printf("-1\n");
		}
		else
		{
			if(maxInner>maxOuter2)
				printf("%d\n",rindex+1);
			else
				printf("-1\n");
		}
	}
	return 0;
}
