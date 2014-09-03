#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>

char str[11]="ALLIZZWELL";

using namespace std;
int main()
{
	int H,W,t,i,j;
		stack<int> Xloc;
		stack<int> Yloc;

	scanf("%d",&t);
	while(t--)
	{		
		char input[102][102];
		char line[102];
		int cache[102][102];
		
		for(i=0;i<102;i++)
			for(j=0;j<102;j++)
				cache[i][j]=input[i][j]=0;

		while(!Xloc.empty())
		{
			Xloc.pop();
			Yloc.pop();
		}
		//cin>>H>>W;
		scanf("%d%d",&H,&W);
		for(i=0;i<H;i++)
		{
			cin>>line;
			//scanf("%s",line);
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
		H++;
		W++;
		/*for(i=0;i<W;i++)
			cache[H][i]=0;
*/
		int locX,locY,currLen=0;		
		while(!Xloc.empty())
		{
			locX=Xloc.top();
			locY=Yloc.top();
			Xloc.pop();
			Yloc.pop();
//			printf("x=%dy=%d\n",locX,locY);
			if(locY > 0 && (input[locX][locY]==str[currLen] && input[locX][locY-1]==str[currLen+1]) && cache[locX][locY-1]==0)
			{
				cache[locX][locY-1]=1;//input[locX][locY-1]-64;
				Xloc.push(locX);
				Yloc.push(locY-1);
				currLen++;
//				printf("%c %d",str[currLen],currLen);
				if(currLen==10)
					break;
				//else
				//	continue;
				//cout<<input[locX][locY-1]<<endl;
			}

			if(locY < W-1 && (input[locX][locY]==str[currLen] && input[locX][locY+1]==str[currLen+1]) && cache[locX][locY+1]==0)
			{				
				cache[locX][locY+1]=1;//input[locX][locY+1]-64;
				Xloc.push(locX);
				Yloc.push(locY+1);
				currLen++;
				if(currLen==10)
					break;
				//else
				//	continue;
				//cout<<input[locX][locY+1]<<endl;
			}

			if(locX > 0 && (input[locX][locY]==str[currLen] && input[locX-1][locY]==str[currLen+1]) && cache[locX-1][locY]==0)
			{
				
				cache[locX-1][locY]=1;//input[locX-1][locY]-64;
				Xloc.push(locX-1);
				Yloc.push(locY);
				currLen++;
				if(currLen==10)
					break;
				//else
				//	continue;

				//cout<<input[locX-1][locY]<<endl;
			}

			if(locX < H-1 && (input[locX][locY]==str[currLen] && input[locX+1][locY]==str[currLen+1]) && cache[locX+1][locY]==0)
			{
				
				cache[locX+1][locY]=1;//input[locX+1][locY]-64;
				Xloc.push(locX+1);
				Yloc.push(locY);
				currLen++;
				if(currLen==10)
					break;
				//else
				//	continue;

				//cout<<input[locX+1][locY]<<endl;
			}

			if(locX > 0 && locY > 0 && (input[locX][locY]==str[currLen] && input[locX-1][locY-1]==str[currLen+1])&& cache[locX-1][locY-1]==0)
			{
				
				cache[locX-1][locY-1]=1;//input[locX-1][locY-1]-64;
				Xloc.push(locX-1);
				Yloc.push(locY-1);
				currLen++;
				if(currLen==10)
					break;
				//else
				//	continue;

				//cout<<input[locX-1][locY-1]<<endl;
			}

			if(locX > 0 && locY < W-1 && (input[locX][locY]==str[currLen] && input[locX-1][locY+1]==str[currLen+1]) && cache[locX-1][locY+1]==0)
			{
				
				cache[locX-1][locY+1]=1;//input[locX-1][locY+1]-64;
				Xloc.push(locX-1);
				Yloc.push(locY+1);
				currLen++;
				if(currLen==10)
					break;
				//else
				//	continue;

				//cout<<input[locX-1][locY+1]<<endl;
			}	

			if(locX < H-1 && locY > 0 && (input[locX][locY]==str[currLen] && input[locX+1][locY-1]==str[currLen+1]) && cache[locX+1][locY-1]==0)
			{
				
				cache[locX+1][locY-1]=1;//input[locX+1][locY-1]-64;
				Xloc.push(locX+1);
				Yloc.push(locY-1);
				currLen++;
				if(currLen==10)
					break;
				//else
				//	continue;

				//cout<<input[locX+1][locY-1]<<endl;
			}

			if(locX < H-1 && locY < W-1 && (input[locX][locY]==str[currLen] && input[locX+1][locY+1]==str[currLen+1]) && cache[locX+1][locY+1]==0)
			{
				
				cache[locX+1][locY+1]=1;//input[locX+1][locY+1]-64;	
				Xloc.push(locX+1);
				Yloc.push(locY+1);
				currLen++;
				if(currLen==10)
					break;
				//else
				//	continue;

				//cout<<input[locX+1][locY+1]<<endl;
			}
		}

		if(currLen==10)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}


