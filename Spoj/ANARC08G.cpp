#include <cstdio>
#include <algorithm>
using namespace std;

#define gc getchar_unlocked

void si(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

int arr[1010][1010];
int main()
{
	int n,i,j,t=1;
	while(true)
	{
		int ans1=0,ans2=0;
		si(n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				si(arr[i][j]);
				ans1+=arr[i][j];
			}
		}
		int profit,loss;
		for(i=0;i<n;i++)
		{
			profit=loss=0;
			for(j=0;j<n;j++)
				loss+=arr[i][j];

			for(j=0;j<n;j++)
				profit+=arr[j][i];
			if(loss-profit>0)
				ans2+=loss-profit;
		}
		printf("%d. %d %d\n",t++,ans1,ans2);
	}
	return 0;
}

