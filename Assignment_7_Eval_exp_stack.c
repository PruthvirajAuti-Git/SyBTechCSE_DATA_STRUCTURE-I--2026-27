#include<stdio.h>
#include<ctype.h>
#define max 100
int stack[max];
int top=-1;

void pushval(int val);
int popval();
int calc(int c1, int c2, char op);
void eval(char post[max]);


void pushval(int val)
{
    if (top >=max- 1)
    {
        printf("Stack full\n");
        return;
    }
    stack[++top] = val;
}

int popval()
{
    if (top < 0)
    {
        printf("Stack empty\n");
         return 0;
    }
    return stack[top--];
}


int main()
{     
    char post[max];
     int choice ;
do
{
    printf("Enter 1 to Eval of Postfix Exp:\n");
     printf("Enter 2 to Eval of prefix Exp:\n");
    printf("Enter your choice : ");
     scanf("%d",&choice);
     
    switch(choice)
    {    case 1:
            {
        
                printf("Enter an Postfix  Expresion :\n");
                scanf("%s",post);
                top=-1;
                eval(post);
                break;
            }
        case 2:
        {

            printf("Enter an prefix Expration :\n");
            break;
        }
        default:
        {
            printf("Invalid choice.....,Try again!!!!\n");
            break;
        }
    }

}while(choice<=2);


return 0;
}



int calc(int c1, int c2, char op)
{
    int ans = 0;

    switch (op)
    {
        case '+':
             ans = c1 + c2;
            break;
        case '-':
             ans = c1 - c2;
            break;
        case '*':
            ans = c1 * c2;
            break;
        case '/':
            if (c2 != 0)
                 ans = c1 / c2;
            else
                printf("\nError: Division by zero!");
            break;
        default:
            printf("\nUnknown operator: %c", op);
    }
    return ans;
}

void eval(char post[max])
{int i, z, op1, op2, ans;
    for (i = 0; post[i] != '\0'; i++)
    {
        if (isalpha(post[i]))
        {
            printf("\nEnter value of %c: ", post[i]);
            scanf("%d", &z);
            pushval(z);
        }
        else
        {
            op2 = popval();
            op1 = popval();
            ans = calc(op1, op2, post[i]);
            pushval(ans);
        }
    }
    printf("\nEvaluation is: %d\n", stack[top]);
}


