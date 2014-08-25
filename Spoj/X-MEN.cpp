#include <cstdio>
#include <iostream>

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

int w[1000004],m[1000004],loc[1000004];


int LIS(int n)  
{  
    int i, k, l, r, mid;   
      
    m[1] = w[1], k = 1;  
    for(i = 2; i <= n; i++)  
    {  
        if(m[k] < w[i])
		m[++k] = w[i];  
        else 
	{  
            l = 1; r = k;  
            while(l <= r)  
            {  
                mid = ( l + r ) / 2;  
                if(m[mid] < w[i])   
                    l = mid + 1;  
                else    
                    r = mid - 1;          
            }  
            m[l] = w[i];  
        }  
    }  
    return k;  
}  

int main()
{
	int n,t,i,p;
	scanint(t);
	while(t--)
	{
		scanint(n);
		for(i=1;i<=n;i++)
			scanint(m[i]);

		for(i=1;i<=n;i++)
		{
			scanint(p);
			loc[p]=i;
		}
		for(i=1;i<=n;i++)
		{
			w[i]=loc[m[i]];
		}
		printf("%d\n",LIS(n));
	}

	return  0;
}
