#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long int max(long long int a,long long int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		int n;
		scanf("%d",&n);
		long int *arr=(long int*)calloc(n,sizeof(long int));
		long long int *choice=(long long int*)calloc(n,sizeof(long long int));
		
		for(int i=0; i<n; i++)
		{
			scanf("%ld",&arr[i]);
		}
		
		long long int m=0;
		for(long int i=0;i<n;i++)
		{
			if(i==0)
				choice[i]=arr[i];
			else if(i==1)
				choice[i]=max(arr[i],arr[i-1]);
			else
				choice[i]=max(choice[i-1],choice[i-2]+arr[i]);
			
			m=max(m,choice[i]);
		}	
		cout<<"Case "<<j<<": "<<m<<endl;
	}
	
	return 0;
}
