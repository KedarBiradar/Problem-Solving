#include <cstdio>
typedef long long int lli;
using namespace std;

	int arr[3000003];
int main()
{
	lli n,m,max,count,res,j,i;
	scanf("%lld%lld",&n,&m);

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	if(arr[0]<m)
	{
		res=max=arr[0];
		count=1;
	}
	else
	{
		count=0;
		res=max=0;
	}
	for(i=1;i<n;i++)
	{
		if(max+arr[i]<=m)
		{
			max+=arr[i];
			count++;
		}
		else if(arr[i]<=m)
		{
			j=i-count;
			while(max+arr[i]>m && j<i)
			{
				max-=arr[j++];
				count--;
			}
			if(i==j)
			{
				count=1;
				max=arr[j];
			}
			else
			{
				count++;
				max+=arr[i];
			}
		}
		else
		{
			count=0;
			max=0;
		}

		if(res<max)
			res=max;
	}
	printf("%lld\n",res);

	return 0;
}
