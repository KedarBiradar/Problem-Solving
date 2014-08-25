
#include <cstdio>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector <int> &v)
{
	int maax=1,n=v.size(),i,j;
	vector <int> LS(n,1);
	for(i=1;i<n;i++)
	{
		int mx=-1;
		for(j=0;j<i;j++)
		{
			if(v[j] < v[i] &&(mx==-1 || LS[mx]<LS[j]))
			{
				mx=j;
				//LS[i]=LS[j]+1;
			}
		}
		if(mx!=-1)
			LS[i]+=LS[mx];

		maax=max(maax,LS[i]);
	}
	return maax;
}
int main()
{

	int c,n,mn,count,i,j,t;
	int matrix[4][110];
	scanf("%d%d",&c,&n);
	t=c*n;

	vector <int> color(t),number(t),v(t),index;
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&color[i],&number[i]);
	}
	for(i=0;i<c;i++)
		index.push_back(i);

	mn=1000000000;
	do
	{
		count=0;
		for(i=0;i<c;i++)
		{
			for(j=0;j<n;j++)
			{
				matrix[index[i]][j]=count++;
			}
		}
		for(i=0;i<t;i++)
		{
				v[i]=matrix[color[i]-1][number[i]-1];
		}
		mn=min(mn,t-LIS(v));
	}while(next_permutation(index.begin(),index.end()));

	printf("%d\n",mn);
	return 0;
}
