#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{

	string str;
	long long int t,n,m,len,max,min,i,countA;
	scanf("%lld",&t);
	while(t--)
	{
		cin>>str;
		scanf("%lld%lld",&n,&m);
		len=str.size();

		if(n==m)
		{
			printf("%lld %lld\n",len,len);
			continue;
		}
		else if(n>m)
		{
			min=max=len;
			countA=i=0;
			while(i<len)
			{
				if(str[i]=='a')
				{
					countA++;
					if(countA==n)
					{
						min+=m-n;
						countA=0;
					}
				}
				else
					countA=0;
				i++;
			}
			printf("%lld %lld\n",min,max);
			//calculate min;

		}
		else
		{
			min=max=len;
			countA=i=0;
			while(i<len)
			{
				if(str[i]=='a')
				{
					countA++;
					if(countA==n)
					{
						max+=m-n;
						countA=0;
					}
				}
				else
					countA=0;
				i++;
			}
			printf("%lld %lld\n",min,max);
			//calculate max;
		}
	}
	return 0;
}
