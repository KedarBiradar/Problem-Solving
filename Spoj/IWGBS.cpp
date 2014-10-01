/*
Find the number of binary sequences of length N possible with no consecutive zeroes and
without leading zeroes
*/


#include<stdio.h>

long long A[10010],B[10010];

void precompute()
{
	A[0]=0;
	B[0]=0;
	A[1]=1;
	B[1]=1;
	A[2]=2;
	B[2]=1;
	for(int i=3;i<=10010;i++)
	{
		A[i]=(A[i-1]+B[i-1])%1000000007;
		B[i]=A[i-1];
	}
}

int main()
{
	long long int n;
	//int t;
	precompute();
	//scanf("%d",&t);	
	//while(t--)
	//{
		scanf("%lld",&n);
		printf("%lld\n",A[n]+B[n]);
	//}

	return 0;
} 

/*
N = int (input());
A = [0,1];
B = [0,1];
i = 2;
while i <= N:
	a = A[i-1]+B[i-1];
	A.append(a);
	B.append(A[i-1]);
	i = i+1;
print(A[N]+B[N]);

*/
