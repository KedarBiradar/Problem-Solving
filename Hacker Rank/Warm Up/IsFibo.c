#include <stdio.h>
long long int array[1000001];
long long int index;
void fillArray()
{

	long long int a,b,c;
	a=0,b=1;
	c=a+b;
	array[0]=0;
	array[1]=1;
	while(c<10000000001)
	{
		array[index++]=c;
		a=b;
		b=c;
		c=a+b;
	}
}

int searchArray(long long int n,int low,int high)
{
	/*
	long long int mid=(low+high)/2;

	if(array[mid]==n)
		return 1;
	else if(array[mid]>n)
		high=mid-1;
	else
		*/

	long long int i;
	for(i=0;i<index;i++)
		if(array[i]==n)
			return 1;

	return 0;	
}
int main()
{
	long long int t,n;
	
	fillArray();
	scanf("%lld",&t);

	while(t>0)
	{
		scanf("%lld",&n);
	
		if(searchArray(n,0,index))
			printf("IsFibo\n");
		else
			printf("IsNotFibo\n");
		t--;
	}
	return 0;
}
