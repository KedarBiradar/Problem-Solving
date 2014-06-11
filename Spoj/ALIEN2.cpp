#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	long int n,k;
	int Ai[10001],Bi[10001],t1,t2,i;
	scanf("%ld%ld",&n,&k);

	for(i=0;i<n;i++)
		scanf("%d",&Ai[i]);

	for(i=0;i<n;i++)
		scanf("%d",&Bi[i]);	
	//AA[0]=Ai[0];
	//BB[0]=Bi[0];

	for(i=1;i<n;i++)
	{
		t1=Ai[i];
		t2=Bi[i];
	
		Ai[i]+=Ai[i-1];
		Bi[i]+=Bi[i-1];

		if(Bi[i]>Ai[i]+t2)
			Bi[i]=Ai[i]+t2;
		else if(Ai[i]>Bi[i]+t1)
			Ai[i]=Bi[i]+t1;

		if(Bi[i] > k && Ai[i] > k )
			break;
	}

		printf("%d %d\n",i,Ai[i-1] < Bi[i-1] ? Ai[i-1] : Bi[i-1]);
	return 0;
}
