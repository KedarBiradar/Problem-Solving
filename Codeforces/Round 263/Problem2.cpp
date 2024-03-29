#include <cstdio>
#include <algorithm>

using namespace std;

long long freq[26];

bool compare(int a,int b)
{
	return a>b;
}
void process(char str[],int n,int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		freq[str[i]-65]++;
	}
	sort(freq,freq+26,compare);
	long long sum=0,curr=0;
	i=0;
	for(i=0;i<26;i++)
	{
		if(curr+freq[i]<=k)
		{
			sum=sum+(freq[i]*freq[i]);
			curr+=freq[i];
		}
		else
		{
			sum=sum+((curr-k)*(curr-k));
			break;
		}
	}
	printf("%lld\n",sum);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	char str[n+1];
	scanf("%s",str);
	process(str,n,k);
}
