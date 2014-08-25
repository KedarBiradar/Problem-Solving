#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct box
{
	long long h,w,d;
};


struct box input[10001],rot[30001];
long long height[10001];

/*int compare(box s1,box s2)
{
	return s1.w*s1.d > s2.w*s2.d;
}*/

int compare (const void *a, const void * b)
{
    return ( (*(box *)b).d * (*(box *)b).w ) -
           ( (*(box *)a).d * (*(box *)a).w );
}
long long boxStack(int n)
{
	int i,j,index=0;
	for(i=0;i<n;i++)
	{
		
		rot[index].h=input[i].h;
		rot[index].w=input[i].w;
		rot[index].d=input[i].d;

		index++;
		rot[index].h=input[i].w;
		rot[index].d=max(input[i].h,input[i].d);
		rot[index].w=min(input[i].h,input[i].d);

		index++;
		rot[index].h=input[i].d;
		rot[index].d=max(input[i].h,input[i].w);
		rot[index].w=min(input[i].h,input[i].w);
		index++;
	}

	n*=3;
	qsort (rot, n, sizeof(rot[0]), compare);

	for(i=0;i<n;i++)
	{
		height[i]=rot[i].h;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if ( rot[i].w < rot[j].w && rot[i].d < rot[j].d && height[i] < height[j] + rot[i].h)
				height[i] = height[j] + rot[i].h;
		}
	}
	long long max=-1;

	for(i=0;i<n;i++)
		if(max<height[i])
			max=height[i];
	return max;
}
int main()
{

	int i,n;
	
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;

		for(i=0;i<n;i++)
			scanf("%lld%lld%lld",&input[i].h,&input[i].w,&input[i].d);

		printf("%lld\n",boxStack(n));		

	}

	return 0;
}
