#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int arr[m];
	int i,fd;
	for(i=0;i<m;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&fd);
	int count=0;
	for(i=0;i<m;i++)
	{
		int res=fd^arr[i];
		int bit=0;
		for(int l=res;l>0;l/=2)
				bit+=(l&1);

		if(bit<=k)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
