/*
Consider a table with 2 rows and 2N columns (a total of 4N cells). Each cell of the first row is coloured by one of the colours A, B, C, D such that there are no two adjacent cells of the same colour. You have to colour the second row using colours A, B, C, D such that:

• There are exactly N cells of each colour (A, B, C and D) in the table.

• There are no two adjacent cells of the same colour. (Adjacent cells share a vertical or a horizontal side.)

It is guaranteed that the solution, not necessarily unique, will always exist.
Input

[a natural number N ≤ 50000]

[a string of 2N letters from the set {A, B, C, D}, representing the first row of the table]
Output

[a string of 2N letters from the set {A, B, C, D}, representing the second row of the table]
Example

Input

1

CB

Output

AD

 

Input

2

ABAD 

Output

BCDC

*/

#include <cstdio>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n,i;
	//string str;
	scanf("%d",&n);
	char str[2*n+1];
	scanf("%s",str);
	i=0;
	char str2[2*n+1],tmp;
	i=0;
	set < char >s;
	set < char >::iterator it;
	while(i < 2*n )
	{
		s.insert('A');
		s.insert('B');
		s.insert('C');
		s.insert('D');
		if(i==0)
		{
			s.erase(str[i]);
			s.erase(str[i+1]);
			it=s.begin();
			str2[i]=*it;
			it++;
			str2[i+1]=*it;
		}
		else
		{
			s.erase(str[i]);
			s.erase(str[i+1]);
			it=s.begin();
			str2[i]=*it;
			it++;
			str2[i+1]=*it;
			if(str2[i-1]==str2[i])
			{
				tmp=str2[i+1];
				str2[i+1]=str2[i];
				str2[i]=tmp;
			}
		}
		i+=2;
	}
	str2[2*n]='\0';
	printf("%s\n",str2);
	return 0;
}
