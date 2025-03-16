#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int coeff;
    int x, y, z;
    struct node *link;
} NODE;
NODE *getnode()
{
    NODE *x;
    x = (NODE *)malloc(sizeof(NODE));
    return x;
}
NODE *readpoly()
{
    NODE *temp, *cur, *head;
    char ch;
    head = getnode();
    head->coeff = -1;
    head->x = -1;
    head->y = -1;
    head->z = -1;
    head->link = head;
    do
    {
        temp = getnode();
        printf("Enter the coefficient\n");
        scanf("%d", &temp->coeff);
        printf("Enter the exponents in dec order\n");
        scanf("%d%d%d", &temp->x, &temp->y, &temp->z);
        cur = head;
        while (cur->link != head)
            cur = cur->link;
        cur->link = temp;
        temp->link = head;
        printf("Do u want to add more coeff (y/n)");
        ch = getchar();
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return head;
}
int compare(NODE *a, NODE *b)
{
    if (a->x > b->x)
        return 1;
    else if (a->x < b->x)
        return -1;
    else if (a->y > b->y)
        return 1;
    else if (a->y < b->y)
        return -1;
    else if (a->z > b->z)
        return 1;
    else if (a->z < b->z)
        return -1;
    return 0;
}
void attach(int cf, int x1, int y1, int z1, NODE **ptr)
{
    NODE *temp;
    temp = getnode();
    temp->coeff = cf;
    temp->x = x1;
    temp->y = y1;
    temp->z = z1;
    (*ptr)->link = temp;
    *ptr = temp;
}
NODE *addpoly(NODE *a, NODE *b)
{
    NODE *starta, *c, *lastc;
    int sum = 0, done = 0;
    starta = a;
    a = a->link;
    b = b->link;
    c = getnode();
    c->coeff = -1;
    c->x = -1;
    c->y = -1;
    c->z = -1;
    lastc = c;
    do
    {
        switch (compare(a, b))
        {
        case -1:
            attach(b->coeff, b->x, b->y, b->z, &lastc);
            b = b->link;
            break;
        case 0:
            if (starta == a)
            {
                done = 1;
            }
            else
            {
                sum = a->coeff + b->coeff;
                if (sum)
                    attach(sum, a->x, a->y, a->z, &lastc);
                a = a->link;
                b = b->link;
            }
            break;
        case 1:
            if (starta == a)
                done = 1;
            attach(a->coeff, a->x, a->y, a->z, &lastc);
            a = a->link;
            break;
        }
    } while (!done);
    lastc->link = c;
    return c;
}
void print(NODE *ptr)
{
    NODE *cur;
    cur = ptr->link;
    while (cur != ptr)
    {
        printf("%d*x^%d*y^%d*z^%d", cur->coeff, cur->x, cur->y, cur->z);
        cur = cur->link;
        if (cur != ptr)
            printf("+");
    }
}
void evaluate(NODE *ptr)
{
    NODE *cur;
    int x, y, z, ex, ey, ez, cof;
    int res = 0;
    printf("Enter the values of x,y and z\n");
    scanf("%d%d%d", &x, &y, &z);
    cur = ptr->link;
    while (cur != ptr)
    {
        ex = cur->x;
        ey = cur->y;
        ez = cur->z;
        cof = cur->coeff;
        res += cof * pow(x, ex) * pow(y, ey) * pow(z, ez);
        cur = cur->link;
    }
    printf("The result is %d\n", res);
}
void main(void)
{
    int ch;
    NODE *a = NULL, *b, *c;
    while (1)
    {
        printf("1.EVALUATE\n2.ADDITION OF 2 POLYNOMIALS\n3.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the details for ploynomial A");
            a = readpoly();
            printf("The polynomial is\n");
            print(a);
            evaluate(a);
            break;
        case 2:
            printf("POLY 1");
            a = readpoly();
            printf("The polynomial is\n");
            print(a);
            printf("POLY 2");
            b = readpoly();
            printf("The polynomial is\n");
            print(b);
            c = addpoly(a, b);
            printf("Sum of two polynomial is\n");
            print(c);
            printf("\n");
            break;
        case 3:
            return;
        default:
            printf("Invalid choice");
            break;
        }
    }
}