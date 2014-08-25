#include <cstdio>
#include <iostream>
typedef long long lli;

using namespace std;
lli flag[1000001];

lli recursiveCall(lli n)
{

	if(n<1000001)
		return flag[n];
	else
		return max(n,(recursiveCall(n/2)+recursiveCall(n/3)+recursiveCall(n/4)));
}

int main()
{

	lli n,i;
	for(i=0;i<12;i++)
		flag[i]=i;

	for(i=12;i<1000001;i++)
		flag[i]=max(i,flag[i/2]+flag[i/3]+flag[i/4]);

	while(scanf("%lli",&n)!=EOF)
	{
		printf("%lld\n",recursiveCall(n));
	}
	return 0;
}
