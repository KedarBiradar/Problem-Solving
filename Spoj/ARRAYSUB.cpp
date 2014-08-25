#include <cstdio>
#include <deque>	
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


int array[1000010];
int B[1000010];
/*
void maxInWindow(int *A, int n, int k)
{
	deque<int> Q;
	for (int i = 0; i < k; i++) 
	{
		while (!Q.empty() && A[i] >= A[Q.back()])
		Q.pop_back();
		Q.push_back(i);
	}

	for (int i = k; i < n; i++) 
	{
		B[i-k] = A[Q.front()];
		while (!Q.empty() && A[i] >= A[Q.back()])
			Q.pop_back();

		while (!Q.empty() && Q.front() <= i-k)
			Q.pop_front();

			Q.push_back(i);
  }
  B[n-k] = A[Q.front()];

	for(int i=0;i<n-k+1;i++)
		printf("%d ",B[i]);

	printf("\n");
}
*/
int main()
{
	int n,i,j,max,k,index;
	//scanf("%d",&n);
	scanint(n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		//scanf("%d",&array[i]);
			scanint(array[i]);
	}
	//scanf("%d",&k);
	scanint(k);


	//maxInWindow(array,n,k);
	max=array[0];
	index=0;
	for(i=1;i<k;i++)
		if(max<array[i])
		{
			max=array[i];
			index=i;
		}
	printf("%d ",max);
	for(;i<n;i++)
	{
		if(array[i]>max)
		{
			max=array[i];
			index=i;
		}
		else if(index<i-k+1)
		{
			max=array[i-k+1];
			index=i-k+1;
			for(j=i-k+2;j<=i;j++)
			{
				if(max<array[j])
				{
					max=array[j];
					index=j;
				}
			}
		}
		printf("%d ",max);
	}
	printf("\n");
	return 0;
}
