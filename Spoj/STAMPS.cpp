#include <cstdio>
#include <algorithm>
typedef long long lli;

#define gc getchar_unlocked

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


using namespace std;
int main()
{
	int t;
	lli need,frnd,*A,tst=0,i,sum;
	scanf("%d",&t);
	while(t--)
	{
		tst++;
		scanint(need);
		scanint(frnd);
		A=new lli[frnd];
		sum=0;
		for(i=0;i<frnd;i++)
		{
			scanint(A[i]);
			sum+=A[i];
		}
		if(sum<need)
		{
			printf("Scenario #%lld:\nimpossible\n\n",tst);
			continue;
		}
		else if(sum==need)
		{
			printf("Scenario #%lld:\n%lld\n\n",tst,frnd);
			continue;
		}
		sort(A,A+frnd);
		sum=0;
		for(i=frnd-1;i>=0;i--)
		{
			sum+=A[i];
			if(sum>=need)
			{
				printf("Scenario #%lld:\n%lld\n\n",tst,frnd-i);
				break;
			}
		}


		delete A;
	}
	return 0;
}
