#include <cstdio>
#include <set>
#include <vector>
#include <iostream>

using namespace std;
int s[40],dp[40][40];
int recursion(int start,int end,int rem)
{

	if(dp[start][rem]!=-1)
		return dp[start][rem];

	if(rem<0)
		return 0;

	/*if(end-start+1<rem)
		return 0;
	*/
	if(start>end)
		return 0;

	if(start==end)
	{
		if(rem==1 && s[start]==0)
		{	return 1;}
		else if(rem==1 && s[start]==1)
		{	return 0;}

		else if(rem>1)
		{	return 0;}
	}

	if(s[start]==1)
		 dp[start][rem]=recursion(start+1,end,rem+1);
	else
		dp[start][rem]=recursion(start+1,end,rem+1)+recursion(start+1,end,rem-1);

	return dp[start][rem];
}
int main()
{
	int n,k,num,tst;
	scanf("%d",&tst);
	while(tst--)
	{
		for(int i=0;i<40;i++)
		{
			s[i]=0;
			for(int j=0;j<40;j++)
				dp[i][j]=-1;
		}
		scanf("%d %d",&n,&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&num);
			s[num]=1;
		}	
		printf("%d\n",recursion(1,2*n,0));	
	}
	return 0;
}
