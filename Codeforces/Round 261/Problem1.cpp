#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int x1,x2,y1,y2,x3,y3,x4,y4,slope;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	if(x1==x2)
	{
		slope=abs(y2-y1);
		x3=x4=x1+slope;
		y3=y1;
		y4=y2;
	}
	else if(y1==y2)
	{
		slope=abs(x2-x1);
		y3=y4=y1+slope;
		x3=x1;
		x4=x2;
	}
	else
	{


	if(abs(x1-x2)!=abs(y1-y2))
	{
		printf("-1\n");
		return 0;
	}
		x3=x2;
		y3=y1;
		x4=x1;
		y4=y2;
	}

		printf("%d %d %d %d\n",x3,y3,x4,y4);
		return 0;
}
