#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long array[1000010];
int main()
{
	long long i,n,min=LLONG_MAX,max=LLONG_MIN,c1=0,c2=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&array[i]);
		if(array[i]<min)
		{
			min=array[i];
			c1=1;
		}
		else if(array[i]==min)
		{
			c1++;
		}
		if(array[i]>max)
		{
			max=array[i];
			c2=1;
		}
		else if(array[i]==max)
		{
			c2++;
		}
	}

	long long temp;
	if(c2==n&&c1==n)
		temp=(c2*(c1-1))/2;
	else
		temp=c2*c1;

	printf("%lld %lld\n",max-min,temp);
	return 0;
}

