#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{

	long int n,i;
	scanf("%ld",&n);
	long long int arr[n],diff;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
	}

	sort(arr,arr+n);

	diff=arr[1]-arr[0];
	//pair1=arr[0];
	//pair2=arr[1];

	for(i=1;i<n-1;i++)
	{
		if((arr[i+1]-arr[i])<diff)
		{
			diff=arr[i+1]-arr[i];
	//		pair1=arr[i];
	//		pair2=arr[i+1];
		}
	}

	for(i=0;i<n-1;i++)
	{
		if((arr[i+1]-arr[i])==diff)
		{
		//	diff=arr[i+1]-arr[i];
		//	pair1=arr[i];
		//	pair2=arr[i+1];
			printf("%lld %lld ",arr[i],arr[i+1]);
		}
	}

	//printf("%lld %lld",pair1,pair2);
	return 0;
}
