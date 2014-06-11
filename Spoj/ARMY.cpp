# include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long int t,ng,nm,i;
	cin>>t;
	while(t--)
	{
		cin>>ng>>nm;
		long int NG[ng],NM[nm];
		for(i=0;i<ng;i++)
			cin>>NG[i];

		for(i=0;i<nm;i++)
			cin>>NM[i];

		sort(NG,NG+ng);

		sort(NM,NM+nm);

		if(NG[ng-1]>=NM[nm-1])
			cout<<"Godzilla\n";
		else
			cout<<"MechaGodzilla\n";

	}

	return 0;
}
