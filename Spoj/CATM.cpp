#include <cstdio>
#include <algorithm>


using namespace std;

#define gc getchar_unlocked

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc());
	if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
	if(neg) x=-x;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int x,y,k,ratX,ratY,cat1X,cat1Y,cat2X,cat2Y;
	int steps,catSteps,i;
	scanint(x);
	scanint(y);
	scanint(k);
	
	for(i=0;i<k;i++)
	{
		scanint(ratX);
		scanint(ratY);
		scanint(cat1X);
		scanint(cat1Y);
		scanint(cat2X);
		scanint(cat2Y);

		if(ratX==x || ratY==y)
		{
			printf("YES\n");
			continue;
		}
		//case 1
		steps=ratY-1;
		catSteps=min(abs(cat1X-ratX)-1+abs(cat1Y-1),abs(cat2X-ratX)-1+abs(cat2Y-1));
		if(steps<=catSteps)
		{
			printf("YES\n");
			continue;
		}
		//case 2
		steps=y-ratY;
		catSteps=min(abs(cat1X-ratX)-1+abs(y-cat1Y),abs(cat2X-ratX)-1+abs(y-cat2Y));
		if(steps<=catSteps)
		{
			printf("YES\n");
			continue;
		}
		//case 3
		steps=ratX-1;
		catSteps=min(abs(cat1Y-ratY)-1+abs(cat1X-1),abs(cat2Y-ratY)-1+abs(cat2X-1));
		if(steps<=catSteps)
		{
			printf("YES\n");
			continue;
		}

		//case 4
		steps=x-ratX;
		catSteps=min(abs(x-cat1X)+abs(ratY-cat1Y)-1,abs(x-cat2X)+abs(ratY-cat2Y)-1);
		if(steps<=catSteps)
		{
			printf("YES\n");
			continue;
		}

		printf("NO\n");
	}
	return 0;
}
