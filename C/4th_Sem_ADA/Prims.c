#include<stdio.h>
int cost[10][10];
int i,j,n,mincost=0;
int union1(int i,int j,int parent[10]);
int find(int i,int parent[10]);
int Kruskal(int cost[10][10],int n,int mincost);
int main()
{
printf("Enter the no. of vertices:\n");
scanf("%d",&n);
 printf ("Enter cost matrix\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
	}
}
printf("The entered cost matrix is\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		printf("%d\t",cost[i][j]);
	}
	printf("\n");
}

printf("Kruskal's MST edges and cost are \n");
mincost=Kruskal(cost,n,mincost);
printf("\nMST cost is %d\n", mincost);
printf("----------");
}

	 int Kruskal(int cost[10][10],int n,int mincost)
	{
		int ne=1,min;
		int a=0,b=0,u=0,v=0;
		int parent[10];
		while(ne<n)
		{
			min=999;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(cost[i][j]<min)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}
			u=find(u,parent);
			v=find(v,parent);
			if(union1(u,v,parent)!=0)
			{
				printf("%d) min edge is ",ne++);
				printf("(%d,%d) and cost is %d\n",a,b,min);
				mincost+=min;
				parent[v]=u;
			}
			cost[a][b]=cost[b][a]=999;
		}
	return mincost;
			
	}
 int find(int i,int parent[10])
{
	while(parent[i]!=0)
		i=parent[i];
	return i;
}
 int union1(int i,int j,int parent[10])
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	else
		return 0;
}