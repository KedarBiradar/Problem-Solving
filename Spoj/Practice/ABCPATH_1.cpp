#include <stdio.h>
#include <string.h>

int H,W;
char input[52][52];
int cache[52][52];
int check(int locX,int locY)
{
	int dir[8]={0,0,0,0,0,0,0,0},max,l;	
	if(locX>=0 && locX<H && locY>=0 && locY<W )
	{
		if(locY > 0 && (input[locX][locY]+1==input[locX][locY-1]))
		{
			if(cache[locX][locY-1]>0)
				dir[0]=cache[locX][locY-1];
			else
			{
				dir[0]=check(locX,locY-1)+1;
				cache[locX][locY-1]=dir[0];
			}
		} 

		if(locY < W-1 && (input[locX][locY]+1==input[locX][locY+1]))
		{
			if(cache[locX][locY+1]>0)
				dir[1]=cache[locX][locY+1];
			else
			{
				dir[1]=check(locX,locY+1)+1;
				cache[locX][locY+1]=dir[1];
			}
			//dir[1]=check(locX,locY+1)+1;
		} 
		
		if(locX > 0 && (input[locX][locY]+1==input[locX-1][locY]))
		{
			if(cache[locX-1][locY]>0)
				dir[2]=cache[locX-1][locY];
			else
			{
				dir[2]=check(locX-1,locY)+1;
				cache[locX-1][locY]=dir[2];
			}
			//dir[2]=check(locX-1,locY)+1;
		} 

		if(locX < H-1 && (input[locX][locY]+1==input[locX+1][locY]))
		{
			if(cache[locX+1][locY]>0)
				dir[3]=cache[locX+1][locY];
			else
			{
				dir[3]=check(locX+1,locY)+1;
				cache[locX+1][locY]=dir[3];
			}
			//dir[3]=check(locX+1,locY)+1;
		} 

		if(locX > 0 && locY > 0 && (input[locX][locY]+1==input[locX-1][locY-1]))
		{
			if(cache[locX-1][locY-1]>0)
				dir[4]=cache[locX-1][locY-1];
			else
			{
				dir[4]=check(locX-1,locY-1)+1;
				cache[locX-1][locY-1]=dir[4];
			}
			//dir[4]=check(locX-1,locY-1)+1;
		} 

		if(locX > 0 && locY < W-1 && (input[locX][locY]+1==input[locX-1][locY+1]))
		{
			if(cache[locX-1][locY+1]>0)
				dir[5]=cache[locX-1][locY+1];
			else
			{
				dir[5]=check(locX-1,locY+1)+1;
				cache[locX-1][locY+1]=dir[5];
			}
			//dir[5]=check(locX-1,locY+1)+1;
		} 

		if(locX < H-1 && locY > 0 && (input[locX][locY]+1==input[locX+1][locY-1]))
		{
			if(cache[locX+1][locY-1]>0)
				dir[6]=cache[locX+1][locY-1];
			else
			{
				dir[6]=check(locX+1,locY-1)+1;
				cache[locX+1][locY-1]=dir[6];
			}
			//dir[6]=check(locX+1,locY-1)+1;
		} 

		if(locX < H-1 && locY < W-1 && (input[locX][locY]+1==input[locX+1][locY+1]))
		{
			if(cache[locX+1][locY+1]>0)
				dir[7]=cache[locX+1][locY+1];
			else
			{
				dir[7]=check(locX+1,locY+1)+1;
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
}

int main()
{
	int i,j,locX[51],locY[51],xi,yi,countA,t=1,max;
	char line[51];
	while(1)
	{


		countA=yi=xi=0;
		scanf("%d%d",&H,&W);

		if(H==0 && W==0)
			break;

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
		max=0;
		for(i=0;i<countA;i++)
		{
			if(max<check(locX[i],locY[i])+1)
				max=check(locX[i],locY[i])+1;
		}
		printf("Case %d: %d\n",t,max);
		t++;
	}
	return 0;
}
