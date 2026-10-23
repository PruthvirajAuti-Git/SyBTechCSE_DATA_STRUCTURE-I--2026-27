#include <stdio.h>
#include <string.h>

typedef struct print_job
{
    int job_id;
    char job_title[20];
}Job;

Job queue[20];
int front = -1;
int rear = -1;

int isempty();
int isfull();
void enque(Job job);
void deque();
void display();


int main()
{    Job job;
    int choice;
    do
    {
     printf("\nEnter 1 to add to queue\n");
        printf("Enter 2 to remove from queue\n");
        printf("Enter 3 to display queue\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("job details\n");
                printf("Enter job id : ");
                scanf("%d",&job.job_id);
                printf("Enter job title :\n");
                 scanf("%s",job.job_title);
                 printf("\n");
                enque(job);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;

        }
    }while(choice<=3);
    return 0;
}



int isempty()
{
    if(front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int isfull()
{
   if(rear == 19)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enque(Job job)
{
    if(isfull())
    {
        printf("Queue  full\n");
    }
    else
    {
        if(isempty())
        {
            front = 0;
        }
        rear++;
        queue[rear].job_id = job.job_id;
        strcpy(queue[rear].job_title, job.job_title);
        printf("Job has been queued\n");
    }
}

void deque()
{
    if(isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        Job save = queue[front];
        printf("Deleted job id is %d and title is %s\n",save.job_id, save.job_title);
        front++;
        if(front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    if(isempty())
    {
        printf("Queue empty\n");
    }
    else
    {
        printf("Job s\n");
        for(int i = front; i <= rear; i++)
        {
            printf("Job id : %d\n", queue[i].job_id);
            printf("Job title : %s\n", queue[i].job_title);
        }
    }
}
