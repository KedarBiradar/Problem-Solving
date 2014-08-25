#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

int LCS[81][81];
char X[81],Y[81];
map<string,bool> isPresent[81][81];

void backTrack(int i,int j,set<string>& sequence,string word )
{
	if(isPresent[i][j].find(word) != isPresent[i][j].end())
		return;
	if(i==0 || j==0)
	{
		sequence.insert(word);
	}
	else if(X[i-1]==Y[j-1])
	{
		word=X[i-1]+word;
		backTrack(i-1,j-1,sequence,word);
	}
	else if(LCS[i][j-1]>LCS[i-1][j])
	{
		backTrack(i,j-1,sequence,word);
	}
	else if(LCS[i-1][j]>LCS[i][j-1])
	{
		backTrack(i-1,j,sequence,word);
	}
	else
	{
		backTrack(i,j-1,sequence,word);
		backTrack(i-1,j,sequence,word);
	}
	isPresent[i][j][word]=true;
}
int main()
{

	int t,i,j,len1,len2;
	scanf("%d",&t);
	//int LCS[81][81];
	//char X[81],Y[81];

		set <string> sequence;
		set<string>::iterator it;
	while(t--)
	{
		sequence.clear();
		scanf("%s%s",X,Y);
		len1=strlen(X);
		len2=strlen(Y);

		for(i=0;i<=len1;i++)
			LCS[i][0]=0;
		for(j=0;j<=len2;j++)
			LCS[0][j]=0;

		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(X[i-1]==Y[j-1])
					LCS[i][j]=LCS[i-1][j-1]+1;
				else
					LCS[i][j]=max(LCS[i][j-1],LCS[i-1][j]);
			}
		}
		backTrack(len1,len2,sequence,"");
		for(it=sequence.begin();it!=sequence.end();it++)
			printf("%s\n",it->c_str());			

			printf("\n");
	}
	return 0;
}
