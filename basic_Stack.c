#include<stdio.h>
#include<stdlib.h>
int stack[20];
int top = -1;
int isfull();
void push(int value);
void pop();
int isempty();
void ispalindrome();


int main()
{     int choice ;
do
{
    printf("\nEnter 1 to push\n");
     printf("Enter 2 to pop\n");
    printf("Enter your choice : ");
     scanf("%d",&choice);
     
    switch(choice)
    {    case 1:
            {
                int value;
                printf("Enter value : ");
                scanf("%d",&value);
                push(value);
                break;
            }
        case 2:
        {
            pop();
            break;
        }
        default:
        {
            printf("Invalid choice\n");
            break;
        }
    }

}while(choice<=2);
return 0;
}

int isfull()
{
   if(top == 19)
        return 1;
    else
        return 0;
}


int isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if(isfull())
    {
        printf("Stack is full\n");
    }
    else
    {
        top = top + 1;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}
void pop()
{
    if(isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top = top - 1;
    }
}
