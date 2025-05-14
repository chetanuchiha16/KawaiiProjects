	#include<stdio.h>
	void read_matrix(int n,int a[10][10])
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
	}
	void find_indegree(int n,int a[10][10],int indegree[])
	{
		int i,j,sum;
		for(j=0;j<n;j++)
		{
			sum=0;
			for(i=0;i<n;i++)
			sum+=a[i][j];
			indegree[j]=sum;
		}
	}
	void topo(int n,int a[10][10])
	{
		int i,s[10],indegree[10],k,u,v,t[10],top;
		find_indegree(n,a,indegree);
		top=-1;
		k=0;
		for(i=0;i<n;i++)
		{
			if(indegree[i]==0)
			s[++top]=i;
		}
		while(top!=-1)
		{
			u=s[top--];
			t[k++]=u;
			for(v=0;v<n;v++)
			{
				if(a[u][v]==1)
				{
					indegree[v]--;
					if(indegree[v]==0)
					s[++top]=v;
				}
			}
		}
		if(k!=n)
		printf("\nTopological Sequence not possible\n");
		else
		{
			printf("\nThe Topological Sequence\n");
			for(i=0;i<n;i++)
			printf("%d\t",t[i]);
		}
	}
	int main()
	{
		int n,a[10][10];
		printf("enter number of nodes\n");
		scanf("%d",&n);
		printf("Enter adjacency matrix\n");
		read_matrix(n,a);
		topo(n,a);
		return 0;
	}