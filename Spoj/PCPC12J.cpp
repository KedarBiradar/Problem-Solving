#include <cstdio>

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
	int t,n,arr[102],i,max,ai,j;
	scanint(t);
	
	while(t--)
	{
		scanint(n);
		for(i=0;i<102;i++)
			arr[i]=0;
		for(i=0;i<n;i++)
		{
			scanint(ai);
			arr[ai]++;
		}
		j=max=0;
		for(i=0;i<101;i++)
		{
			if(max<arr[i] && arr[i]%i ==0 )
			{
				max=arr[i];
				j=i;
			}
		}
		if(j!=0)
			printf("%d\n",j);
		else
			printf("-1\n");

	}

	return 0;
}
