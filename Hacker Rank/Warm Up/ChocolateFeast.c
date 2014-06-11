#include <stdio.h>
#include <math.h>

long long int countChoc(int n,int c,int m)
{

	long long int temp,temp1,temp2,temp3;
	temp=n/c;
	temp1=temp/m;
	temp2=temp%m;
	temp3=temp+temp1;
	if(temp1+temp2>=m)
	{
		temp3+=countChoc((temp1+temp2)*c,c,m);
	}
		return temp3;
}

long long int count2(int n,int c,int m)
{
	long long int total,noOfCh,noOfWr,noOfRemCh;
	total=0;
	while(1)
	{
		noOfCh=n/c;
		noOfWr=noOfCh/m;
		noOfRemCh=noOfCh%m;
		total+=noOfRemCh+noOfWr;
		if((noOfRemCh+noOfWr)<m)
		{
			break;
		}
		else
		{
			total+=noOfRemCh+noOfWr;
			n=noOfRemCh+noOfWr;
		}

	}
	return total;
}

int main()
{

	long long int n,t,c,m;
	long long int answer;
	scanf("%lld",&t);
	while(t>0)
	{

		scanf("%lld%lld%lld",&n,&c,&m);
		answer=countChoc(n,c,m);
		//answer=count2(n,c,m);
		printf("%lld\n",answer);
		t--;
	}

	return 0;
}
