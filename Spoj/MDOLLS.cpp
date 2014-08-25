#include <cstdio>
#include <algorithm>
#include <vector>
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

struct tuple
{
    int h,w;
    //tuple(int s,int p) : h(s), w(p) {}

bool operator < (const tuple& t2) const
    {
	if(h==t2.h)
		return (w < t2.w);
	else
		return (h > t2.h);
    }
};

struct less_than_key
{
    inline bool operator() (const tuple& struct1, const tuple& struct2)
    {
        if (struct1.h == struct2.h)
			return (struct1.w < struct2.w);
	else
			return (struct1.h > struct2.h);
    }
};

bool compare(tuple t1,tuple t2)
{
	return (t1.w<t2.w);
}


tuple arr[20001];
int main()
{

	int t,n,res,i;
	scanf("%d",&t);
	while(t--)
	{
		scanint(n);
		for(i=0;i<n;i++)
		{
			scanint(arr[i].h);
			scanint(arr[i].w);
		}
		sort(arr,arr+n);
		res=n;
		tuple *it2=arr;
		for(i=0;i<n;i++)
		{
			tuple prev=arr[i];
			tuple *it=upper_bound(arr,it2,prev,compare);
			if(it!=it2)
			{
				res--;
				it->w=prev.w;
			}
			else
			{
				*(it2++)=prev;
			
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
