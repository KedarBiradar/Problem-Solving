#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{
	int t;
	long int n,m,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		if(m==0)
		{
			printf("2 %ld\n",n);
			continue;
		}
		
		int arr[n+1];
		for(i=1;i<=n;i++)
			arr[i]=i-1;
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&a,&b);
			arr[a]++;
			arr[b]--;
		}
		for(i=1;i<=n;i++)
		{
			if(arr[i]==n-1)
			{
				printf("2 %ld\n",i);
				break;
			}
		}
		if(i==n+1)
			printf("1\n");
	}

	return 0;
}
