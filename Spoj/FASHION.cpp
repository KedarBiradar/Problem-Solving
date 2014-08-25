#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int t,n,i,sum,m[1001],w[1001];
	scanf("%d",&t);
	
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&m[i]);

		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		sort(m,m+n);
		sort(w,w+n);
		for(i=0;i<n;i++)
			sum+=(m[i]*w[i]);
		printf("%d\n",sum);

	}

	return 0;
}
