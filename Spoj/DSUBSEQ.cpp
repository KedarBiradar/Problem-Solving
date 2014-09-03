#include <cstdio>
#include <cstring>

int MOD=1000000007;
int mod(int x)
{
	long long m=1000000007;
	return ((x%m)+m)%m;
}

int countSUB(char str[])
{
	int dp[100010],last[26];
	memset(last,-1,sizeof(last));
	int i;
	dp[0]=1;
	int len=strlen(str);	
	for(i=0;i<len;i++)
	{
		dp[i+1]=dp[i]<<1;
		if(dp[i+1]>=MOD)
			dp[i+1]-=MOD;

		if(last[str[i]- 'A' ] != -1)
		{
			dp[i+1]-=dp[ last[str[i]-'A'] -1 ];
			if(dp[i+1]<0)
				dp[i+1]+=MOD;
		}
			last[str[i]-'A']=i+1;
	}
	return dp[len];
}
int main()
{
	int t;
	char str[100010];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		printf("%d\n",countSUB(str));
	}
	return 0;
}
