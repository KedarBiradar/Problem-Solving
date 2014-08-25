#include <cstdio>

long long array[1000001];

void precompute()
{
	long long i;
	array[1]=2;
	for(i=2;i<1000001;i++)
		array[i]=i+array[i-1];
}
int main()
{

	int F,B,M;
	long long D,value;
	precompute();
	while(1)
	{
		scanf("%lld%d%d%d",&D,&F,&B,&M);
		if(D==0 && B==0 && F==0 && M==0)
			break;

		value=D-(array[F]*B);
		if(value<M)
		{
			printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n",M-value);
		}
		else
		{
			printf("Farmer Cream will have %lld Bsf to spend.\n",value);
		}
		
		
	}
}
