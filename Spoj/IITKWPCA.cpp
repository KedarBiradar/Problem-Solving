#include <iostream>
#include <cstdio>
#include <set>
#include <sstream>
#include <cstring>
using namespace std;

int main()
{
	string line,word;
	set<string>s;
	int t;
	cin>>t;
	char ch=getchar();
	while (t--) 
	{
		s.clear();
		getline(std::cin, line);
		istringstream is(line);
		while (is >> word) 
		{
        		s.insert(word);
    		}
		cout<<s.size()<<endl;
	}

	return 0;
}
