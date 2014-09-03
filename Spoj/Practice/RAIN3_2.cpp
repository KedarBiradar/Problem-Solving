#include <cstdio>
#include <climits>
typedef long long int lli;
using namespace std;

int check(lli *A,lli k,lli n,lli size)
{

	lli i;
	lli sum=0;
	for(i=1;i<=size;i++)
	{
		sum+=A[i];
		if(sum>k)
			return -1;
	}
	
	for(;i<=n;i++)
	{
		sum+=A[i]-A[i-size];
		if(sum>k)
			return -1;
	}

	return 1;
}
int main()
{

	int t,flag;
	lli n,k,s0,t0,i;//,sum,j,l,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&s0,&t0,&n,&k);
		lli A[n+1],S[n+1],T[n+1],sum[n+1];		
		flag=0;
		S[0]=s0;
		T[0]=t0;
		A[0]=(S[0]%100 + 1) * (T[0]%100 + 1);
		sum[0]=A[0];
		for(i=1;i<n;i++)
		{
			S[i] = (78901 + 31*S[i-1])%699037;
			T[i] = (23456 + 64*T[i-1])%2097151;
			A[i]=(S[i]%100 + 1) * (T[i]%100 + 1);
			sum[i]=sum[i-1]+A[i];
			if(A[i]>k)
			{
				printf("0\n");
				flag=1;
				break;	
			}
		}

		if(flag==1)
			continue;


		lli p=0,q=1;
		lli len=n;

		lli maxLen=0,minLen=INT_MAX;

		while(q <len && p < len)
		{
			if (sum[q] - sum[p]+ A[p] <= k)
				 q++;
			else 
			{
				if (q-p < minLen) minLen = q-p;
				++ p;
			}

		}

	if (q-p < minLen) 
		minLen = q-p;

	if (minLen == INT_MAX) 
		minLen = 0;

	printf("%lld\n",minLen);
		//cout << minLength << endl;


/*		for(i=1;i<=n;i++)
		{
			if(check(A,k,n,i)==-1)
			{
				printf("%lld\n",i-1);
				break;
			}
		}
		if(i>n)
			printf("%lld\n",n);
*/

/*		lli low,high,mid,prevMid;
		low=1;
		high=n;
		prevMid=-1;

	while(low<high)
	{
		prevMid=mid;
		mid=(low+high)/2;
		if(check(A,k,n,mid)==1)
		{
			//prevMid=mid;
			low=mid+1;
			if(prevMid-mid==1)
			{
				printf("%lld\n",mid);
				break;
			}
			
		}
		else
		{
			//prevMid=mid;
			high=mid-1;
			if(mid-prevMid==1)
			{
				printf("%lld\n",prevMid);
				break;
			}
		}

	}
	if(low>=high)
		printf("%lld\n",low);

*/
	}
	return 0;
}
