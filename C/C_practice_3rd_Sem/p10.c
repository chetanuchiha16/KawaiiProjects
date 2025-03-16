#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}NODE;
NODE* root=NULL;

NODE *create(NODE *root,int data)
{
    
    if(root==NULL)
    {
        NODE *temp;
        temp=(NODE *)malloc(sizeof(NODE));
        temp->data=data;
        temp->lchild=NULL;
        temp->rchild=NULL;
        return temp;

    }
    

    if(data < root->data)
       root-> lchild=create(root->lchild,data);
    else if(data>root->data)
       root-> rchild=create(root->rchild,data);
    return root;
}

NODE *search(NODE *root,int data)
{
    if(root==NULL)
        printf("no ele");
    else if(data<root->data)
        root->lchild=search(root->lchild,data);
    else if(data>root->data)
        root->rchild=search(root->rchild,data);
    else
        printf("Element found is %d",root->data);
    return root;
}

void inorder(NODE *root)
{
    if (root!=NULL)
    {
        inorder(root->lchild);
        printf("%d",root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE *root)
{
    if (root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE *root)
{
    if (root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d",root->data);
    }
}

void main()
{
    int ch,n,data,i;
    while(1)
    {
        printf("\n1.create\n2.search\n3.inorder\n4.preorder\n5.postorder\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter the no of nodesp\n");
                    scanf("%d",&n);
                    printf("Enter the data for the tree\n");
                    for(i=1;i<=n;i++)
                    {
                        scanf("%d",&data);
                        root=create(root,data);
                    }
                    break;
            case 2: printf("Enter the data to search\n");
                   scanf("%d",&data);
                    root=search(root,data);
                    break;
            case 3: printf("Inorder traversal\n");
                    inorder(root);break;
            case 4:printf("Pre oredr traversal\n");
                    preorder(root);break;
            case 5:printf("Post oreder traversal\n");
                    postorder(root);break;

        }          
    }
}