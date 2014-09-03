#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <stdio.h>
#include <set>
using namespace std;

struct tuple
{
    long long int senior,prod;
    tuple(long long int s, long long int p) : senior(s), prod(p) {}

bool operator < (const tuple& t2) const
    {
	if(senior==t2.senior)
		return (prod > t2.prod);
	else
		return (senior > t2.senior);
    }
bool operator()(const tuple& obj) const
 {
   return (obj.senior== senior && obj.prod==prod);
 }
};

struct less_than_key
{
    inline bool operator() (const tuple& struct1, const tuple& struct2)
    {
        if (struct1.senior == struct2.senior)
			return (struct1.prod > struct2.prod);
	else
			return (struct1.senior > struct2.senior);
    }
};

int main()
{
	vector < tuple > input;
	map< string , tuple > list;

	int m;
	long long int i,Si,Pi,l;
	char Ai;
	char Ni[50];
	scanf("%d",&m);
	long long int total=0;
	for(i=0;i<m;i++)
	{
		//scanf("%c",&Ai);
		//scanf("%s",Ni);
		cin>>Ai>>Ni;
		//scanf("%s",Ni);
		if(Ai=='A')
		{
			scanf("%lld%lld",&Si,&Pi);
			//cin>>Si>>Pi;
			//input.push_back(tuple(Si,Pi));
			tuple t(Si,Pi);
			if(input.size()==0)
			{
				total=0;
				input.push_back(t);
			}
			else if(input.size()==1)
			{
				//vector <tuple>::iterator low1;
				//low1=lower_bound(input.begin(),input.end(),t,less_than_key());
				//input.insert(low1,t);								
				//input.push_back(t);


		
				if(t.senior < input[0].senior)
				{
					input.push_back(t);
				}
				else if(t.senior > input[0].senior)
				{
					input.push_back(input[0]);
					input[0].senior=t.senior;
					input[0].prod=t.prod;
				}
				else if( t.prod < input[0].prod )
				{
					input.push_back(t);
				}
				else
				{
					input.push_back(input[0]);
					input[0].senior=t.senior;
					input[0].prod=t.prod;				
				}


				total=input[0].prod*input[1].prod;	
				//sort(input.begin(),input.end(),less_than_key());			
			}	
			else
			{
/*
				for(unsigned int j=0;j<input.size();j++)
				{
					//prod+=input[j].prod*input[j+1].prod;	
					cout<<input[j].senior<<"\t"<<input[j].prod<<endl;
				}
*/				vector <tuple>::iterator low;			
				low=lower_bound(input.begin(),input.end(),t,less_than_key());
//				cout<<(*low).senior<<"\t"<<(*low).prod<<endl;				
				//up=upper_bound(input.begin(),input.end(),t);
				//l=std::distance(input.begin(), low);
				l=low-input.begin();
//				cout<<"lower boundry="<<l<<endl;
				if(l==0)
				{
					total+=(Pi*input[l].prod);

				}
				else if(l==input.size())
				{

					total+=(input[l-1].prod*Pi);
				}
				else
				{
					//u=std::distance(input.begin(), up);
					total-=(input[l-1].prod*input[l].prod);
					total+=((input[l-1].prod*Pi)+(Pi*input[l].prod));
				}
				input.insert(low,t);
/*
				for(unsigned int j=0;j<input.size();j++)
				{
					//prod+=input[j].prod*input[j+1].prod;	
					cout<<input[j].senior<<"\t"<<input[j].prod<<endl;
				}*/
			}
			printf("%lld\n",total);
			//cout<<total<<endl;
			list.insert(pair< string , tuple >(Ni,t));
		}
		else
		{
			tuple t1=list.find(Ni)->second;
			vector <tuple> :: iterator it;
			it=find_if(input.begin(),input.end(),tuple(t1.senior,t1.prod));
			if(it!=input.end())
			{
				unsigned int index=it-input.begin();//std::distance(input.begin(), it);
				//cout<<"Index is "<< index<<endl;
				//cout<<input[index].senior<<"\t"<<input[index].prod<<endl;
				if(input.size()<2)
					total=0;
				else
				{
					if(index==0)
					{
						total-=(input[index].prod*input[index+1].prod);
					}
					else if(index==input.size()-1)
					{
						total-=(input[index-1].prod*input[index].prod);
					}
					else
					{
						total-=((input[index-1].prod*input[index].prod)+(input[index].prod*input[index+1].prod));
						total+=(input[index-1].prod*input[index+1].prod);
					}
				}

				input.erase(it);			
				//list.erase(Ni);
				//cout<<total<<endl;			
				printf("%lld\n",total);
			}			
			
		}

	}	
	return 0;
}
