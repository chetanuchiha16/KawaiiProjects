#include <stdio.h>
#include <stdlib.h>
int m,n,*ht,key[20];
int count=0;

void insert(int key)
{
    int index;
    if(count==m)
    {
        printf("the hash table is full\n");
    }

    index=key%m;
    if(ht[index]!=-1)
    {
        printf("collision detected at %d:\n",key);
        while(ht[index]!=-1)
        {
            index=(index+1)%m;
        }

    }
    ht[index]=key;
    count++;
}

void main()
{
    int i;
    printf("Enter the no of employees\n");
    scanf("%d",&n);

    printf("Enter the  hash table size\n");
    scanf("%d",&m);

    ht=(int*)malloc(m*sizeof(int));

    for(i=0;i<m;i++)
    {
        ht[i]=-1;

    }
    printf("Enter the keys for %d employees\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&key[i]);
    }

    for(i=0;i<n;i++)
    {
        insert(key[i]);
    }

    for(i=0;i<m;i++)
    {
        printf("%d\n",ht[i]);
    }
}