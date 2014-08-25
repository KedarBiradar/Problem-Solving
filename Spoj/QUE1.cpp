#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define gc getchar_unlocked

void ss(int &x)
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
	int h,p;
	tuple(){}
	tuple(int _h,int _p): h(_h),p(_p){}
};

struct less_than_key
{
    inline bool operator() (const tuple& struct1, const tuple& struct2)
    {
			return (struct1.h > struct2.h);
    }
};



int main()
{
	int t,n,i;
	ss(t);

		vector <int> s;
		vector <int>:: iterator it;
		vector <tuple> v;
	while(t--)
	{
		ss(n);
		int height[n+1],pos[n+1];
		s.clear();
		v.clear();
		for(i=0;i<n;i++)
			ss(height[i]);
		for(i=0;i<n;i++)
			ss(pos[i]);

		for(i=0;i<n;i++)
		{
			v.push_back(tuple(height[i],pos[i]));
		}
		sort(v.begin(),v.end(),less_than_key());
		s.push_back(v[0].h);
		for(i=1;i<n;i++)
		{
			int num,loc;
			num=v[i].h;
			loc=v[i].p;
			it=s.begin();
			while(loc>0 && it!=s.end())
			{
				if(*it>num)
					loc--;
				it++;
			} 
			s.insert(it,num);
		}
		for(it=s.begin();it!=s.end();it++)
			printf("%d ",*it);
		printf("\n");

	}

	return 0;
}
