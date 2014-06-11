#include <cstdio>
#include <algorithm>

typedef long long int lli;

using namespace std;

#define gc getchar_unlocked

void scanint(lli &x)
{
	register lli c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

int main()
{

	lli n,m,arr[1000001];
	lli i,h,low,mid,high;
	//scanf("%d%d",&n,&m);
	scanint(n);
	scanint(m);
	scanint(arr[0]);
	//scanf("%d",&arr[0]);
	low=0;
	high=arr[0];


	for(i=1;i<n;i++)
	{
		//scanf("%d",&arr[i]);
			scanint(arr[i]);
		/*if(low>arr[i])
			low=arr[i];
		*/
		if(high<arr[i])
			high=arr[i];
	}
	//printf("Low=%lld High=%lld",low,high);	

	while(low<high)
	{
		mid=(low+high)/2;
		h=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]>mid)
				h+=(arr[i]-mid);
		}

		if(h==m)
		{
			printf("%lld\n",mid);
			break;
		}
		else if(h>m)
			low=mid+1;
		else
			high=mid;
	}

	if(low>=high)
		printf("%lld\n",low-1);
	//printf("Low=%lld High=%lld",low,high);	

	//sort(arr,arr+n);
/*
	cache[0]=0;
	for(i=1;i<n;i++)
		cache[i]=cache[i-1]+(arr[i]-arr[i-1]);
*/	

	/*h=0;
	for(i=n-1;i>0;i--)
	{
		
		h+=(n-i)*(arr[i]-arr[i-1]);
		if(h<m)
			continue;
		else if(h==m)
			printf("%lld\n",arr[i-1]);
		else
		{
			while(h>m)
				h-=(n-i);
		}
	}*/
	return 0;
}

