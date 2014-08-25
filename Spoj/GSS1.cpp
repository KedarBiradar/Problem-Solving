#include <cstdio>
#include <climits>

using namespace std;
#define LOG2_MAXN 15
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

struct node
{
	int min,max,best;
};

node tree[1<<(LOG2_MAXN+2)];
int array[50004];
int C[50008];
int s,e,random;
int maxx(int a,int b)
{
	return a>b?a:b;
}

int minn(int a,int b)
{
	return a<b?a:b;
}

void buildTree(int index,int low,int high)
{
	if(low==high)
	{
		if(low==0)
		{
			tree[index].min=tree[index].max=tree[index].best=0;
		}
		else
		{
			tree[index].min=C[low-1];
			tree[index].max=C[low];
			tree[index].best=C[low]-C[low-1];
		}
	}
	else
	{
		int mid=(low+high)/2;
		buildTree(2*index+1,low,mid);
		buildTree(2*index+2,mid+1,high);
		tree[index].min=minn(tree[2*index+1].min,tree[2*index+2].min);
		tree[index].max=maxx(tree[2*index+1].max,tree[2*index+2].max);
		tree[index].best=maxx(tree[2*index+2].max-tree[2*index+1].min,maxx(tree[2*index+1].best,tree[2*index+2].best));
	}
}


int findRange(int index,int low,int high)
{
	if(s<=low && high<=e )
	{
		int res=tree[index].best;
		if(random!=INT_MAX)
			res=maxx(res,tree[index].max-random);
		random=minn(random,tree[index].min);
		return res;
	}
	else
	{
		int mid=(low+high)/2;
		if(mid<s)
			return findRange(2*index+2,mid+1,high);
		else if(mid>=e) 
			return findRange(2*index+1,low,mid);
		else
			return maxx(findRange(2*index+2,mid+1,high),findRange(2*index+1,low,mid));
	}
}
int solve(int x,int y,int n)
{
	s=x;
	e=y;
	random=INT_MAX;
	return findRange(0,0,n);
}
int main()
{
	int n,m,i,xi,yi;
	scanint(n);
	for(i=0;i<n;i++)
		scanint(array[i]);
	C[0]=0;
	for(i=1;i<n;i++)
		C[i+1]=C[i]+array[i];
	buildTree(0,0,n);
	scanint(m);
	for(i=0;i<m;i++)
	{
		scanint(xi);
		scanint(yi);
		printf("%d\n",solve(xi,yi,n));
	}
	return 0;
}

/*long long max(long long a,long long b)
{
	return a>b?a:b;
}
long long kadane(int start,int end)
{
	int i;
	long long max_so_far = array[start];
	long long curr_max = array[start];
 
   for (i = start+1; i <= end; i++)
   {
        curr_max = max(array[i], curr_max+array[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}*/

