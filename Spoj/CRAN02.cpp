
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
	

	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n;
		scanf("%d",&n);
		 std::map<long long int,long long int> mymap;
		
  		//int* arr=(int*)calloc(n,sizeof(int));
		long long int result[n];
		long long int temp;
		long long int count=0;
	
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&temp);
			if(i==0)
			{
				result[0]=temp;
			//	mymap.insert( std::pair<long long int,long int>(temp,1) );
			//	continue;
			}
			else
				result[i]=result[i-1]+temp;
			mymap[result[i]]++;
		//	cout<<mymap[0]<<endl;
		/*	if(mymap.find(result[i])==mymap.end())
			{
				mymap.insert( std::pair<long long int,long int>(result[i],1) );
			}
			else
			
				mymap[result[i]]=mymap[result[i]]+1;
		*/		
				
		}
		std::map<long long int,long long int>::iterator it;

  		for (it=mymap.begin(); it!=mymap.end(); it++)
  		{
  			long long int np=it->second;
  			
  			if(it->first==0)
  				count=count+np+np*(np-1)/2;	
  		//	cout<<np<<endl;
  			else
  				count=count+np*(np-1)/2;
  		}
	
		cout<<count<<endl;
		mymap.clear();
	}
	
	return 0;
}

