#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector <int> B;
	int A[1000001];
	long int n,m,i,no;

	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>no;
		B.push_back(no);
	}
	
	//auto it;
vector<int>::iterator it;
	for(i=0;i<n;i++)
	{
		
		it=find(B.begin(),B.end(),A[i]);
		if(it!=B.end())
			B.erase(it);
	}

		sort(B.begin(),B.end());
//		sort( vec.begin(), vec.end() );
		B.erase( unique( B.begin(), B.end() ), B.end() );
	 for (unsigned j=0; j<B.size(); ++j)
    		cout << B[j]<<" ";
	//cout<<B;
}
