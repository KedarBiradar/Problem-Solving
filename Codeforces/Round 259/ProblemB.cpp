//O(n)
#include <cstdio>
#include <limits.h>

int array[100010];
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int minn=INT_MAX;
	int st=0;

	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
		if(array[i]<minn)
		{
			minn=array[i];		
			st=i;
		}
	}

	bool flag=false;
	for(i=st;i<n-1;i++)
	{
		if(array[i]>array[i+1])
		{
			flag=true;
			break;
		}		
	}
	if(flag==true)
	{
		printf("-1\n");
		return 0;
	}

	for(i=1;i<st-1;i++)
	{
		if(array[i]<array[i-1] || array[i]<array[n-1])
		{
			flag=true;
			break;
		}
	
	}
	if(flag==true)
	{
		printf("-1\n");
		return 0;
	}	
	else
	{
		if(st==0)
			printf("0\n");
		else
			printf("%d\n",n-st);
	}
	return 0;
}