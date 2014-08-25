#include <cstdio>
#include <algorithm>

using namespace std;

#define gc getchar_unlocked
typedef long long int lli;

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

	lli t,n,i,j,a,b,c,flag,p;
	scanint(t);
	while(t--)
	{
		scanint(n);
		lli arr[n];
		for(i=0;i<n;i++)
		{
			scanint(arr[i]);
		}
		scanint(p);
		sort(arr,arr+n);
		flag=0;
		for(i=0;i<n;i++)
		{
			a=arr[i];
			for(j=i+1;j<n;j++)
			{
				b=arr[j];
				c=p-(a+b);
				if(binary_search(arr+j+1,arr+n,c))
				{
					printf("YES\n");
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}

		if(flag==0)
			printf("NO\n");

	}

}
