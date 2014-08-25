#include <cstdio>
#include <map>
typedef long long lli;
using namespace std;

int main()
{
	int t;
	lli sum,i,n,key,count;
	scanf("%d",&t);
	while(t--)
	{
		map <lli,lli>m;
		map <lli,lli>::iterator it;
		printf("\n");
		scanf("%lld",&n);
		lli arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		count=sum=0;
		m.insert(make_pair(0,1));
		for(i=0;i<n;i++)
		{
			sum+=arr[i];
			key=sum-47;
			if(key>=0)
			{	it=m.find(key);
				if(it!=m.end())
				{
					count+=it->second;
				}
			}
			it=m.find(sum);
			if(it!=m.end())
				it->second++;
			else
				m.insert(make_pair(sum,1));
		}
		printf("%lld\n",count);
	}
	return 0;
}
