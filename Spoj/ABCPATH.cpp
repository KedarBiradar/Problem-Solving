/*

You will be given a 2-dimensional grid of letters. Find the length of the longest path of consecutive letters, starting at 'A'. Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).

For example, in the following grid, there are several paths from 'A' to 'D', but none from 'A' to 'E':

 
ABC

 

One such path is:

 

path

 

Input:

Each test case will start with a line contains two integers H, W the height and width of the grid respectively 1 <= H, W <= 50. Then H lines follow each of W uppercase letters only. Input terminates with H = 0 and W = 0.

 

Output:

For each test case print “Case C: X” without quotes where C is the case number starting with 1 and X is the solution.

 

Sample Input:

4  3

ABE

CFG

BDH

ABC

0 0

 

Sample Output:

Case_1:_4

 

Note: The underscore '_' symbol is only for clarity you should print space instead.
*/



#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int main()
{
	int H,W,max,t=1,i,j;
	stack<int> Xloc;
	stack<int> Yloc;
	while(true)
	{
		cin>>H>>W;
		if(H==0 && W==0)
			break;

		char input[H][W];
		char line[W];
		int cache[H][W];
	
		for(i=0;i<H;i++)
		{
			cin>>line;
			for(j=0;j<W;j++)
			{
				input[i][j]=line[j];
				cache[i][j]=0;
				if(line[j]==65)
				{
					Xloc.push(i);
					Yloc.push(j);
					cache[i][j]=1;
				}
			}

		}	

		int locX,locY;		
		while(!Xloc.empty())
		{
			locX=Xloc.top();
			locY=Yloc.top();
			Xloc.pop();
			Yloc.pop();

			if(locY > 0 && (input[locX][locY]+1==input[locX][locY-1]) && cache[locX][locY-1]==0)
			{
				cache[locX][locY-1]=input[locX][locY-1]-64;
				Xloc.push(locX);
				Yloc.push(locY-1);
				//cout<<input[locX][locY-1]<<endl;
			}

			if(locY < W-1 && (input[locX][locY]+1==input[locX][locY+1]) && cache[locX][locY+1]==0)
			{				
				cache[locX][locY+1]=input[locX][locY+1]-64;
				Xloc.push(locX);
				Yloc.push(locY+1);
				//cout<<input[locX][locY+1]<<endl;
			}

			if(locX > 0 && (input[locX][locY]+1==input[locX-1][locY]) && cache[locX-1][locY]==0)
			{
				
				cache[locX-1][locY]=input[locX-1][locY]-64;
				Xloc.push(locX-1);
				Yloc.push(locY);
				//cout<<input[locX-1][locY]<<endl;
			}

			if(locX < H-1 && (input[locX][locY]+1==input[locX+1][locY]) && cache[locX+1][locY]==0)
			{
				
				cache[locX+1][locY]=input[locX+1][locY]-64;
				Xloc.push(locX+1);
				Yloc.push(locY);
				//cout<<input[locX+1][locY]<<endl;
			}

			if(locX > 0 && locY > 0 && (input[locX][locY]+1==input[locX-1][locY-1])&& cache[locX-1][locY-1]==0)
			{
				
				cache[locX-1][locY-1]=input[locX-1][locY-1]-64;
				Xloc.push(locX-1);
				Yloc.push(locY-1);
				//cout<<input[locX-1][locY-1]<<endl;
			}

			if(locX > 0 && locY < W-1 && (input[locX][locY]+1==input[locX-1][locY+1]) && cache[locX-1][locY+1]==0)
			{
				
				cache[locX-1][locY+1]=input[locX-1][locY+1]-64;
				Xloc.push(locX-1);
				Yloc.push(locY+1);
				//cout<<input[locX-1][locY+1]<<endl;
			}	

			if(locX < H-1 && locY > 0 && (input[locX][locY]+1==input[locX+1][locY-1]) && cache[locX+1][locY-1]==0)
			{
				
				cache[locX+1][locY-1]=input[locX+1][locY-1]-64;
				Xloc.push(locX+1);
				Yloc.push(locY-1);
				//cout<<input[locX+1][locY-1]<<endl;
			}

			if(locX < H-1 && locY < W-1 && (input[locX][locY]+1==input[locX+1][locY+1]) && cache[locX+1][locY+1]==0)
			{
				
				cache[locX+1][locY+1]=input[locX+1][locY+1]-64;
				Xloc.push(locX+1);
				Yloc.push(locY+1);
				//cout<<input[locX+1][locY+1]<<endl;
			}
		}
		max=0;
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
				if(cache[i][j]>max)
					max=cache[i][j];
			}
		}
		cout<<"Case "<<t<<": "<<max<<endl;		
		t++;
	}

	return 0;
}
