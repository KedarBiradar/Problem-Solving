#include <cstdio>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

    void reverseWords(string &s)
    {
        stack<char> stk;
	long long len=s.size()-1,i;
	i=0;
	while(i <= len && s[i]==' ')
		i++;
	while(len >= i && s[len]==' ')
		len--;

	if(i>len)
	{
		cout<<"";
		return;
	}

	bool flag=false;
	for(;i<=len;i++)
	{
		if(s[i]!=' ')
		{
			stk.push(s[i]);
			if(flag)
				flag=false;
		}
		if(s[i]==' ' && ! flag)
		{
			stk.push(s[i]);
			flag=true;		
		}
	}
	int count=0;
	string word;
	while(!stk.empty())
	{
		if(stk.top()==' ')
		{
			if(count>0)
			{
				cout<<word<<" ";
				count=0;
				word="";
			}
			stk.pop();
		}
		else
		{
			word=stk.top()+word;
			count++;
			stk.pop();
		}
		
	}
	if(count>0)
		cout<<word;

}

int main()
{
	string str;
//	while(1)
//	{
		getline(cin,str);
		//cout<<str<<endl;
		reverseWords(str);
		//cout<<"done";
//	}
	return 0;
}
