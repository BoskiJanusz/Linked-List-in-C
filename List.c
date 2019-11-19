#include <stdio.h>
#include "List.h"
#include <stdbool.h>
#include <stdlib.h>
int main()

{

    int choice, value;
    List head = NULL;

    while (true)
    {
        //system("clear");
        printf("\nMENU \n");
        printf("1. Add \n");
        printf("2. View \n");
        printf("3. Remove from begin \n");
        printf("4. Destroy list \n");
        printf("5. Exit \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Podaj wartosc:");
            scanf("%d", &value);
            push(&head, value);

            break;
        case 2:
            printf("Lista: ");
            printList(head);

            break;
        case 3:
            removeHead(&head);

            break;
        case 4:
            removeList(&head);
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }

        
    }
    return 0;
}

void push(List *head, int value)
{
    List temp = (List)malloc(sizeof(List));
    temp->value = value;
    temp->next = *head;
    *head = temp;
}

void printList(List Node)
{
    while (Node != NULL)
    {
        printf("%d", Node->value);
        Node = Node->next;
    }
}

void removeHead(List *head)
{
    if (*head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        List temp = *head;
        *head = temp->next;

        free(temp);
    }
}

void removeList(List *head)
{
    if (*head)
    {
        removeList(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}
