/*

Problem Description:

                Mr.ESP used to tell “ALL IZZ WELL” whenever he gets into any trouble.

So his friends and the people around him used to laugh at him. But Mr.ESP is very

strong in his belief. He believes that the term “ALL IZZ WELL” will make everything

fine. Now your task is to ignore the story above and find whether there is a path in

the given matrix which makes the sentence “ALL IZZ WELL”

There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.


Input Specification:

                The first line consists of an integer t representing the number of test cases.

The first line of each test case consists of two integers R and C representing the number

of rows and number of columns in the matrix. The description of the matrix follows.

Output Specification:

                For each test case print “YES” if there is a path which makes the sentence “ALLIZZWELL”.

Else print “NO”.

Note: Take care of 4th test case

There is a new line after every test case in the input.


Input constraints:

t<=1000

R<=100

C<=100

Sample Input:

5

3 6

AWE.QX

LLL.EO

IZZWLL


1 10

ALLIZZWELL


2 9

A.L.Z.E..

.L.I.W.L.


3 3

AEL

LWZ

LIZ


1 10

LLEWZZILLA

 

Sample Output:

YES

YES

NO

NO

YES
*/

#include <iostream>
#include <cstdio>

using namespace std;
int cache[102][102];
char input[102][102];
char str[11]="ALLIZZWELL";
char line[102];
int H,W;
int x[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int y[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int isValid(int x,int y)
{
	if(x>=0&&x<H && y>=0 && y<W)
		return 1;
	else
		return 0;
}
int recursiveCall(int i,int j,int len)
{

	int ret;
	cache[i][j]=1;
	if(len==9)
		return 1;
	else
	{
		for(int xi=0;xi<8;xi++)
		{
			if(isValid(i+x[xi],j+y[xi]))
			{
				if(input[i+x[xi]][j+y[xi]]==str[len+1] && cache[i+x[xi]][j+y[xi]]==0)
				{
					cache[i+x[xi]][j+y[xi]]=1;
					ret=recursiveCall(i+x[xi],j+y[xi],len+1);
					if(ret==1)
					{
						return 1;
						cache[i+x[xi]][j+y[xi]]=0;
					}
				}
			}
		}
	}
	cache[i][j]=0;
	return 0;
}
int main()
{

	int t,i,j,flag;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<102;i++)
			for(j=0;j<102;j++)
				cache[i][j]=0;

		scanf("%d%d",&H,&W);
		for(i=0;i<H;i++)
		{
			//cin>>input[i];
			scanf("%s",input[i]);
			/*for(j=0;j<W;j++)
			{
				input[i][j]=line[j];
			}*/
		}	
		flag=0;
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				if(input[i][j]=='A' && recursiveCall(i,j,0))
				{
					printf("YES\n");
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
}
