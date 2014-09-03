#include <cstdio>
#include <set>
#include <vector>
#include <iostream>

using namespace std;
vector<int> s;
int total;
void recursion(int open,int close,set<int> arr,int len)
{
	if(open==0 && close==0)
	{
		int flag=0;
		for(int i=0;i<s.size();i++)
		{
			if(arr.find(s[i])==arr.end())
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			total++;
		return;
	}
	if(open>0)
	{
		arr.insert(len);
		recursion(open-1,close+1,arr,len+1);
	}
	if(close>0)
	{
		arr.erase(len);
		recursion(open,close-1,arr,len+1);
	}
}
int main()
{
	set<int> arr;
	int n,k,num;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&num);
		s.push_back(num);
	}	
	recursion(n,0,arr,1);
	printf("%d\n",total);	
	return 0;
}
