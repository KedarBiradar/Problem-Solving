#include <cstdio>
#include <set>
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

int main()
{

	set <int> s;
	int i,j,n,frnd[100],ffrnd,m;
	
	scanint(n);
	for(i=0;i<n;i++)
	{
		scanint(frnd[i]);
		scanint(m);
		for(j=0;j<m;j++)
		{
			scanint(ffrnd);
			s.insert(ffrnd);
		}

	}
	for(i=0;i<n;i++)
		s.erase(frnd[i]);

	printf("%ld\n",s.size());
	return 0;
}
