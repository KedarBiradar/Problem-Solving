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

int arr1[2010],arr2[2010],dp[2010][2010];

int max(int a,int b)
{
	return a>b?a:b;
}
int LCS(int * arr1,int * arr2,int len1,int len2)
{
	int i,j;
	
	for(i=0;i<=len1;i++)
		dp[0][i]=0;

	for(i=0;i<=len2;i++)
		dp[i][0]=0;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(arr1[i-1]==arr2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len1][len2];
}
int main()
{
	int t;
	si(t);
	while(t--)
	{
		int len1=0,len2,num,max=0;
		
		while(true)
		{
			si(arr1[len1]);
			if(arr1[len1]==0)
				break;
			len1++;
		}
		while(true)
		{
			len2=0;
			si(num);
			if(num==0)
				break;

			arr2[len2]=num;
			len2++;
			while(true)
			{
				si(arr2[len2]);
				if(arr2[len2]==0)
					break;
				len2++;
			}
			int tmp=LCS(arr1,arr2,len1,len2);
			if(max<tmp)
				max=tmp;
		}
		printf("%d\n",max);
	}
	return 0;
}

