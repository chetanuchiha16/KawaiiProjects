#include <stdio.h>
#include <Stdlib.h>
#include <math.h>

typedef struct node
{
    int x,y,z,coef;
    struct node *next;
}NODE;

NODE *getnode()
{
    NODE *x;
    x=(NODE *)malloc(sizeof(NODE));
    return x;
}

NODE *readpoly()
{
    NODE *head=getnode();
    char ch;
    head->x=-1;
    head->y=-1;
    head->z=-1;
    head->coef=-1;
    head->next=head;
    do
    {
        NODE *temp=getnode();
        printf("Enter the coef\n");
        scanf("%d",&temp->coef);
        printf("Enter the exponesnts in decreasing order\n");
        scanf("%d%d%d",&temp->x,&temp->y,&temp->z);
        NODE *cur=head;
        while(cur->next!=head)
            cur=cur->next;
        cur->next=temp;
        temp->next=head;
        printf("do you want more coef\n");
        ch=getchar();
        scanf("%c",&ch);
        
        
    } while (ch == 'y' || ch == 'Y');
    return head;
    

}

void print(NODE *a)
{
    NODE *cur;
    cur=a->next;
    while(cur!=a)
    {
        printf("%d*x^%d*y^%d*z^%d\n",cur->coef,cur->x,cur->y,cur->z);
        cur=cur->next;
        if(cur!=a)
            printf(" + ");
    }
}

void evaluate(NODE *a)
{
    int res=0;
    NODE *cur;
    int x,y,z,ex,ey,ez,cf;
    printf("Enter the value of x,y,z\n");
    scanf("%d%d%d",&x,&y,&z);
    cur=a->next;
    while(cur!=a)
    {
        ex=cur->x;
        ey=cur->y;
        ez=cur->z;
        cf=cur->coef;
        res+=cf*pow(x,ex)*pow(y,ey)*pow(z,ez);
        cur=cur->next;


    }
    printf("\n the result is %d\n",res);


}

int compare(NODE *a,NODE *b)
{
    if(a->x>b->x)
        return 1;
    else if(a->x<b->x)
        return -1;
    else if(a->y>b->y)
        return 1;
    else if(a->y<b->y)
        return -1;
    else if(a->z>b->z)
        return 1;
    else if(a->z<b->z)
        return -1;
    return 0;
}

void attach(int cof,int x1,int y1,int z1,NODE **lastc)
{
    NODE *temp;
    temp=getnode();
    temp->coef=cof;
    temp->x=x1;
    temp->y=y1;
    temp->z=z1;
    (*lastc)->next=temp;
    *lastc=temp;
}

NODE *addpoly(NODE *a,NODE *b)
{
    NODE *starta,*c,*lastc;
    int done=0,sum;
    starta=a;


    a=a->next;
    b=b->next;
    c=getnode();
    c->coef=-1;
    c->x=-1;
    c->y=-1;
    c->z=-1;
    lastc=c;

    do
    {
        switch(compare(a,b))
        {
            case -1: attach(b->coef,b->x,b->y,b->z,&lastc);
            b=b->next;
            break;
            case 0: if(starta==a) done=1;
            else
            {
                sum=a->coef+b->coef;
                if(sum)
                    attach(sum,a->x,b->y,b->z,&lastc);
                a=a->next;b=b->next;

            }
            break;
            case 1: attach(a->coef,a->x,a->y,a->z,&lastc);
            a=a->next;
            break;
        }
    }while(done!=0);
    lastc->next=c;
    return c;


}

void main()
{
    int ch;
    NODE *a,*b,*c;

    while(1)
    {
        printf("\n1.evalueate\n2.add poly\n3.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the elements of poly a\n");
                    a=readpoly();
                    printf("The polynomial is:\t");
                    print(a);
                    evaluate(a);
                    break;
            case 2: printf("Enter the elements of poly A\n");
                    a=readpoly();
                    print(a);
                    printf("Enter poly B\n");
                    b=readpoly();
                    print(b);
                    c=addpoly(a,b);
                    printf("the sum is\n");
                    print(c);
        }   
    }
}