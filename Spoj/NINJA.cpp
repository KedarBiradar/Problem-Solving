#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long long int n,a,b,c,d,arr[4],area;
	while(1)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);

		if(n==0 && a==0 && b==0 &&c==0 && d==0)
		{
			break;
		}
		area=n*n*n;
		if(a+b+c+d!=area)
		{
			printf("Impossible\n");
			continue;
		}
		if(a%n!=0 || b%n!=0 || c%n!=0 || d%n!=0 ) 		
		{
			printf("Impossible\n");
			continue;
		}
		arr[0]=a;
		arr[1]=b;
		arr[2]=c;
		arr[3]=d;
		sort(arr,arr+4);
		if((arr[1]/arr[0]) == (arr[3]/arr[2]))
		{
			arr[0]/=n;
			arr[1]/=n;
			arr[2]/=n;
			arr[3]/=n;
			if(((arr[0]*n)%(arr[2]+arr[0])) == 0 && ((arr[0]*n)%(arr[1]+arr[0])) == 0)
				printf("Possible\n");
			else
				printf("Impossible\n");
		}
		else
				printf("Impossible\n");
	}

	return 0;
}
