#include <stdio.h>
#include <string.h>

int H,W;
char input[102][102],str[11]="ALLIZZWELL";
int cache[102][102],length=10;
int check(int locX,int locY,int currLen)
{
	int dir[8]={0,0,0,0,0,0,0,0},max,l;

	/*
	if(currLen==length)
		return 10;
	*/
	if(locX>=0 && locX<H && locY>=0 && locY<W && currLen <= length)
	{
		if(locY > 0 && (input[locX][locY]==str[currLen] && input[locX][locY-1]==str[currLen+1]))
		{
			if(cache[locX][locY-1]>0)
				/*dir[0]=*/ return cache[locX][locY-1];
			else
			{
				dir[0]=check(locX,locY-1,currLen+1)+1;
				cache[locX][locY-1]=dir[0];
				return dir[0];
			}
		} 

		if(locY < W-1 && (input[locX][locY]==str[currLen] && input[locX][locY+1]==str[currLen+1]))
		{
			if(cache[locX][locY+1]>0)
				/*dir[1]=*/ return cache[locX][locY+1];
			else
			{
				dir[1]=check(locX,locY+1,currLen+1)+1;
				cache[locX][locY+1]=dir[1];
				return dir[1];
			}
			//dir[1]=check(locX,locY+1)+1;
		} 
		
		if(locX > 0 && (input[locX][locY]==str[currLen] && input[locX-1][locY]==str[currLen+1]))
		{
			if(cache[locX-1][locY]>0)
				/*dir[2]=*/ return cache[locX-1][locY];
			else
			{
				dir[2]=check(locX-1,locY,currLen+1)+1;
				cache[locX-1][locY]=dir[2];
				return dir[2];
			}
			//dir[2]=check(locX-1,locY)+1;
		} 

		if(locX < H-1 && (input[locX][locY]==str[currLen] && input[locX+1][locY] == str[currLen+1]))
		{
			if(cache[locX+1][locY]>0)
				/*dir[3]=*/ cache[locX+1][locY];
			else
			{
				/*dir[3]=*/ return check(locX+1,locY,currLen+1)+1;
				cache[locX+1][locY]=dir[3];
			}
			//dir[3]=check(locX+1,locY)+1;
		} 

		if(locX > 0 && locY > 0 && (input[locX][locY]==str[currLen] && input[locX-1][locY-1]==str[currLen+1]))
		{
			if(cache[locX-1][locY-1]>0)
				/*dir[4]=*/ return cache[locX-1][locY-1];
			else
			{
				dir[4]=check(locX-1,locY-1,currLen+1)+1;
				cache[locX-1][locY-1]=dir[4];
				return dir[4];
			}
			//dir[4]=check(locX-1,locY-1)+1;
		} 

		if(locX > 0 && locY < W-1 && (input[locX][locY]==str[currLen] && input[locX-1][locY+1] == str[currLen+1]))
		{
			if(cache[locX-1][locY+1]>0)
				dir[5]=cache[locX-1][locY+1];
			else
			{
				dir[5]=check(locX-1,locY+1,currLen+1)+1;
				cache[locX-1][locY+1]=dir[5];
			}
			//dir[5]=check(locX-1,locY+1)+1;
		} 

		if(locX < H-1 && locY > 0 && (input[locX][locY]==str[currLen+1] && input[locX+1][locY-1]==str[currLen+1]))
		{
			if(cache[locX+1][locY-1]>0)
				dir[6]=cache[locX+1][locY-1];
			else
			{
				dir[6]=check(locX+1,locY-1,currLen+1)+1;
				cache[locX+1][locY-1]=dir[6];
			}
			//dir[6]=check(locX+1,locY-1)+1;
		} 

		if(locX < H-1 && locY < W-1 && (input[locX][locY]==str[currLen] && input[locX+1][locY+1]==str[currLen+1]))
		{
			if(cache[locX+1][locY+1]>0)
				dir[7]=cache[locX+1][locY+1];
			else
			{
				dir[7]=check(locX+1,locY+1,currLen+1)+1;
				cache[locX+1][locY+1]=dir[7];
			}
			//dir[7]=check(locX+1,locY+1)+1;
		} 
	}
		max=dir[0];
		for(l=1;l<8;l++)
		{
			if(dir[l]>max)
				max=dir[l];	
		} 
		return max;
	
	/*else if(currLen==length)
		return 10;*/
}

int main()
{
	int i,j,locX[102],locY[102],xi,yi,countA,t,flag;
	char line[102];

	///printf("%s\n",str);

	scanf("%d",&t);
	while(t--)
	{


		countA=yi=xi=0;
		scanf("%d%d",&H,&W);

		for(i=0;i<H;i++)
		{
			scanf("%s",line);
			for(j=0;j<W;j++)
			{
				input[i][j]=line[j];		
				cache[i][j]=0;
				if(line[j]==65)
				{
						locX[xi++]=i;
						locY[yi++]=j;
						countA++;
				}
			}	
		}
		H++;
		W++;
		flag=0;
		for(i=0;i<countA;i++)
		{

			printf("locx & loc y=%d %d\n",locX[i],locY[i]);
			if(check(locX[i],locY[i],0)>=10)
			{
				printf("YES\n");
				flag=1;
				break;
			}	
		}
		if(flag==0)
			printf("NO\n");	
	}
	return 0;
}
