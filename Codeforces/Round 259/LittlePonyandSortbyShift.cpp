//O(n^2)
#include <cstdio>

int array[100010];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	int count=0;
	for(i=0;i<n;i++)
	{

		for(j=0;j<n-1;j++)
		{
			if(array[j]>array[j+1])
				break;
		}
		if(j==n-1)
		{
			printf("%d",count);
			break;		
		}
		int tmp=array[n-1];
		for(j=n-1;j>0;j--)
		{
			array[j]=array[j-1];
		}
		array[0]=tmp;
		count++;
	}
	if(i==n)
		printf("-1");
	printf("\n");
	return 0;
}
