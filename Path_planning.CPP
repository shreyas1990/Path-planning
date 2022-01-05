#include<iostream.h>
#include<conio.h>
#include<math.h>

#define MAX_OBSTACLES 25 /* maximum number of obstacles */
int num_obstacles = 13; /* number of obstacles */
double obstacle[MAX_OBSTACLES][2] = /* obstacle locations */
{{0.61, 2.743},{0.915, 2.743},{1.219, 2.743},{1.829, 1.219},
{1.829, 1.524},{ 1.829, 1.829}, {1.829, 2.134},{2.743, 0.305},
{2.743, 0.61},{2.743, 0.915},{2.743, 2.743},{3.048, 2.743},
{3.353, 2.743},
{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},
{-1,-1},{-1,-1},{-1,-1}};
double start[2] = {0.305, 1.219}; /* start location */
double goal[2] = {3.658, 1.829}; /* goal location */

int pathMatrix[16][10];
int i,j,row=16,col=10;

void intialize()
{
  for(i=0;i<row;i++)
  {
   for(j=0;j<col;j++)
   {
    pathMatrix[i][j]=0;
   }
  }
}

void Print()
{
 for(i=0;i<row;i++)
 {
  cout<<endl;
  for(j=0;j<col;j++)
  {
   cout<<pathMatrix[i][j]<<"\t";
  }
  if(i==8)
   getch();
 }
}

void MarkObstacles()
{
 int x,y;
 for(i=0;i<num_obstacles;i++)
 {
  x=ceil(obstacle[i][0]/0.305);
  y=ceil(obstacle[i][1]/0.305);
  pathMatrix[x][y]=-1;
 }
}

void MoveUp(int x, int y)
{
 if(x+1<16 & pathMatrix[x+1][y]!=-1)
 {
  if(pathMatrix[x+1][y]==0||pathMatrix[x+1][y]>pathMatrix[x][y]+1)
  {
   pathMatrix[x+1][y]=pathMatrix[x][y]+1;
  }
  MoveUp(x+1,y);
 }
}

void MoveDown(int x, int y)
{
 if(x-1>=0 & pathMatrix[x-1][y]!=-1)
 {
  if(pathMatrix[x-1][y]==0||pathMatrix[x-1][y]>pathMatrix[x][y]+1)
  {
   pathMatrix[x-1][y]=pathMatrix[x][y]+1;
  }
  MoveDown(x-1,y);
 }
}

void MoveRight(int x, int y)
{
 if(y+1<10 & pathMatrix[x][y+1]!=-1)
 {
  if(pathMatrix[x][y+1]==0||pathMatrix[x][y+1]>pathMatrix[x][y]+1)
  {
   pathMatrix[x][y+1]=pathMatrix[x][y]+1;
  }
  MoveRight(x,y+1);
 }
}

void MoveLeft(int x, int y)
{
 if(y-1>=0 & pathMatrix[x][y-1]!=-1)
 {
  if(pathMatrix[x][y-1]==0||pathMatrix[x][y-1]>pathMatrix[x][y]+1)
  {
   pathMatrix[x][y-1]=pathMatrix[x][y]+1;
  }
  MoveLeft(x,y-1);
 }
}
void assign(int x, int y)
{
 MoveUp(x,y);
 MoveDown(x,y);
 MoveLeft(x,y);
 MoveRight(x,y);
}
void MarkAroundObstacles()
{
 int counter=0,o[160];
 for(i=0;i<num_obstacles;i++)
 {
  o[i]=0;
 }
 while(counter<num_obstacles)
 {
  for(i=0;i<num_obstacles;i++)
  {
   if(o[i]==0)
   {
	   int x=ceil(obstacle[i][0]/0.305);
	   int y=ceil(obstacle[i][1]/0.305);
	   int ic=0;
	   do
	   {
		if(x-1>0&&y-1>0&&pathMatrix[x-1][y-1]!=-1)
		{
		 if(pathMatrix[x-1][y-1]>0)
		 {
		  MoveRight(x-1,y-1);
		  MoveDown(x-1,y-1);

		  MoveUp(x-1,y-1);
		  MoveLeft(x-1,y-1);

		  if(pathMatrix[x-1][y]>0)
		  {
		   MoveDown(x-1,y);
		  }
		  ic++;
		 }
		}
		else
		{
		 ic++;
		}

		if(x-1>0&&y+1<col&&pathMatrix[x-1][y+1]!=-1)
		{
		 if(pathMatrix[x-1][y+1]>0)
		 {
		  MoveLeft(x-1,y+1);
		  MoveDown(x-1,y+1);

		  MoveUp(x-1,y+1);
		  MoveRight(x-1,y+1);

		  if(pathMatrix[x][y+1]>0)
		  {
		   MoveRight(x,y+1);
		  }
		  ic++;
		 }
		}
		else
		{
		 ic++;
		}

		if(x+1<row&&y-1>0&&pathMatrix[x+1][y-1]!=-1)
		{
		 if(pathMatrix[x+1][y-1]>0)
		 {
		  MoveRight(x+1,y-1);
		  MoveUp(x+1,y-1);

		  MoveLeft(x+1,y-1);
		  MoveDown(x+1,y-1);
		  if(pathMatrix[x][y-1]>0)
		  {
		   MoveLeft(x,y-1);
		  }
		  ic++;
		 }
		}
		else
		{
		 ic++;
		}

		if(x+1<row&&y+1<col&&pathMatrix[x+1][y+1]!=-1)
		{
		 if(pathMatrix[x+1][y+1]>0)
		 {
		  MoveLeft(x+1,y+1);
		  MoveUp(x+1,y+1);

		  MoveRight(x+1,y+1);
		  MoveDown(x+1,y+1);

		  if(pathMatrix[x+1][y]>0)
		  {
		   MoveUp(x+1,y);
		  }
		  ic++;
		 }
		}
		else
		{
		 ic++;
		}
	   }while(ic>0&&ic<=4);
	   if(ic!=0)
	   {
		counter++;
		o[i]=1;
	   }
   }
  }
 }
}

void FindPath()
{
 int goal_x, goal_y;
 goal_x=ceil(goal[0]/0.305);
 goal_y=ceil(goal[1]/0.305);
 pathMatrix[goal_x][goal_y]=1;
 assign(goal_x,goal_y);
 int temp_x=goal_x, temp_y=goal_y;
 while(/*pathMatrix[start_x][start_y]<0&&*/temp_x>0&pathMatrix[temp_x-1][temp_y]!=-1)
 {
   temp_x--;
   MoveLeft(temp_x,temp_y);
   MoveRight(temp_x,temp_y);
 }
 temp_x=goal_x;
 while(temp_x<row-1& pathMatrix[temp_x+1][temp_y]!=-1)
 {
  temp_x++;
   MoveLeft(temp_x,temp_y);
   MoveRight(temp_x,temp_y);
 }
 while(/*pathMatrix[start_x][start_y]<0&&*/temp_y>0&pathMatrix[temp_x][temp_y-1]!=-1)
 {
   temp_y--;
   MoveUp(temp_x,temp_y);
   MoveDown(temp_x,temp_y);
 }
 temp_y=goal_y;
 while(temp_y<9& pathMatrix[temp_x][temp_y+1]!=-1)
 {
   temp_y++;
   MoveUp(temp_x,temp_y);
   MoveDown(temp_x,temp_y);
 }
 MarkAroundObstacles();
}

void main()
{
 clrscr();
 intialize();
 MarkObstacles();
 FindPath();
 Print();
 int start_x,start_y;
  start_x=ceil(start[0]/0.305);
 start_y=ceil(start[1]/0.305);
 cout<<"\n\nStart["<<start_x<<", "<<start_y<<"]= "<<pathMatrix[start_x][start_y];
 getch();
}