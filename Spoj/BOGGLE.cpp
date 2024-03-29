#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <list>
using namespace std;

int main()
{
	int n,i;
	scanf("%d",&n);
	getc(stdin);
	string line;
	int op[n];
	
	map <string,list<int> > trie;
	map <string ,list<int> >::iterator it;
	for(i=0;i<n;i++)
	{
		list <int> ls;
		op[i]=0;
		getline(cin,line);		
		stringstream ss(line);
		string buff;	
		while(ss>>buff)
		{
				it=trie.find(buff);
				if(it!=trie.end())
				{
					it->second.push_back(i);
				}
				else
				{
					list < int > ls1; 
					ls1.push_back(i);
					trie.insert(make_pair(buff,ls1));
				}
		}
	}

	int index,len;
	for(it=trie.begin();it!=trie.end();it++)
	{
		if(it->second.size()==1)
		{
			index=it->second.front();
			len=it->first.size();
			if(len<=4)
				op[index]+=1;
			else if(len==5)
				op[index]+=2;
			else if(len==6)
				op[index]+=3;
			else if(len==7)
				op[index]+=5;
			else
				op[index]+=11;
		}
	}

	int max=op[0];
	for(i=1;i<n;i++)
		if(max<op[i])
			max=op[i];

	printf("%d\n",max);


	return 0;
}
