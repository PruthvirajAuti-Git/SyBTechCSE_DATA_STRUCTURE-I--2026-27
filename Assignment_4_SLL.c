#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    int regno;
    struct Student *next;
};

struct Student *head = NULL;

void create()
{
    struct Student *newnode, *temp;
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct Student *)malloc(sizeof(struct Student));

        printf("Enter student name: ");
        scanf("%s", newnode->name);
        printf("Enter registration number: ");
        scanf("%d", &newnode->regno);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    printf("Students created successfully.\n");
}

void display()
{
    struct Student *temp;

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    printf("\nStudent Linked List:\n");

    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("Registration Number: %d\n", temp->regno);
        printf("\n");

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\nWorkshop Enrollment\n");
        printf("1. Create Students\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}