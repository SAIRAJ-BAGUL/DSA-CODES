/* IN THIS THE SINGLY LINK LIST IS PERFORMED. */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void create()
{
    struct node *newnode, *temp;
    int choice=1;

    while(choice)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("ENTER DATA :- ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp ->next = newnode;
            temp=newnode;
        }
        printf("ADD ANOTHER NODE (1/0) : ");
        scanf("%d",&choice);
    }
}

void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY \n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}

void insert_first()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("ENTER DATA :- ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insert_end()
{
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA :- ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    temp=head;
    while(temp->next!=NULL)
    {  
        temp=temp->next;
    }
    temp->next=newnode;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
}

void delete_first()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void delete_last()
{
    struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

int main()
{
    create();
    printf("\nOriginal List:\n");
    display();

    insert_first();
    printf("\nAfter Insert First:\n");
    display();

    insert_end();
    printf("\nAfter Insert End:\n");
    display();

    delete_first();
    printf("\nAfter Delete First:\n");
    display();

    delete_last();
    printf("\nAfter Delete Last:\n");
    display();

    return 0;
}