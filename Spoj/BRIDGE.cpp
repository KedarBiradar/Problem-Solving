#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

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

struct tuple
{
	int l,r;
	tuple(){}
	tuple(int n,int p): l(n),r(p){}
};

int compare(tuple t1, tuple t2)
{
	if(t1.r==t2.r)
		return t1.l < t2.l;
	else
		return t1.r < t2.r;
}

int LCS(vector<tuple> arr, int n)
{
	int dp[n+1],i,j;
	for(i=0;i<=n;i++)
		dp[i]=1;

	int max=1;

		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(arr[i].l>=arr[j].l &&  dp[i]<=dp[j])
				{
					dp[i]=dp[j]+1;
					if(max<dp[i])
						max=dp[i];
				}

			}
		}
	return max;
}
int main()
{
	int tst,n,i,num;
	si(tst);
	int lhs[1010];//rhs[1010];
	vector <tuple> arr(1010);
	while(tst--)
	{
		arr.clear();
		si(n);
		for(i=0;i<n;i++)
		{
			si(lhs[i]);		
		}
		for(i=0;i<n;i++)
		{
			si(num);
			arr.push_back(tuple(lhs[i],num));
		}
		sort(arr.begin(),arr.end(),compare);
		printf("%d\n",LCS(arr,n));
	}
	return 0;
}

