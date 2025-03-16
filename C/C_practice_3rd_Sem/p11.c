#include <stdio.h>
#include <stdlib.h>
int q[20], front = -1, rear = -1, s[20], visit[20], top = -1, n, a[20][20];

void create()
{
    int i, j;

    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs(int v)
{
    int i, cur;
    visit[v] = 1;
    q[++rear] = v;
    while (front != rear)
    {
        cur = q[++front];
        for (i = 1; i <= n; i++)
        {
            if (a[cur][i] == 1 && visit[i] == 0)
            {
                q[++rear] = i;
                visit[i] = 1;
                printf("-->%d", i);
            }
        }
    }
}

void dfs(int v)
{
    int i, cur;
    visit[v] = 1;
    s[++top] = v;
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && visit[i] == 0)
        {
            printf("%d-->", i);
            dfs(i);
        }
    }
}

void main()
{
    int ch, v, i;
    while (1)
    {
        printf("\n1.create\n2.bfs\n3.dfs\n4.exit\nenter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            for (i = 1; i <= n; i++)
                visit[i] = 0;
            printf("Enter the first vertice\n");
            scanf("%d", &v);
            printf("The reachable vertices from %d are\t", v);
            bfs(v);

            break;
        case 3:
            for (i = 1; i <= n; i++)
                visit[i] = 0;
            printf("Enter the first vertice\n");
            scanf("%d", &v);
            printf("The reachable vertices from %d are\t", v);
            dfs(v);
            break;
        case 4:
            exit(0);
        }
    }
}