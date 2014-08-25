#include <cstdio>

bool array[1000002];

int digitSum(int d)
{
			int sum=0;
			while(d>0)
			{
				sum+=d%10;
				d=d/10;
			}
	return sum;
}

int main()
{
	int i,sum;
	for(i=0;i<1000002;i++)
		array[i]=false;

	for(i=1;i<1000002;i++)
	{
		sum=i+digitSum(i);
		array[sum]=true;
	}
	//int count=0;
	for(i=1;i<1000000;i++)
		if(array[i]==false)
		{
			printf("%d\n",i);
			//count++;
		}
	//printf("\n%d",count);

	return 0;
}
