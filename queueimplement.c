/*IN THIS WE WILL IMPLEMENT QUEUE USING AN ARRAY FUNDAMENTALS.*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void enqueue(int);
void dequeue();
void peek();
void display();

int queue[SIZE],front=-1,rear=-1;

void main()
{
    int value,choice;
    while(1)
    {
        printf("\n\n*****MENU*****\n");
        printf("1.Insertion \n 2.Deletion \n 3.Display \n 4.peek \n 5.Exit");
        printf("\n ENTER YOUR CHOICE :- ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("ENTER THE VALUE TO BE INSERT :- ");
            scanf("%d",&value);
            enqueue(value);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            peek();
            break;

            case 5:
            exit(0);

            default: 
            printf("\n WRONG SELECTION !!! TRY AGAIN !!!");
        }
    }
}

void enqueue(int value)
{
    if(rear==SIZE-1)
    printf("\n QUEUE IS FULL !!! INSERTION IS NOT POSSIBLE !!!");
    else if(front==-1 &&  rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=value;
        printf("INSERTION SUCCESS");
    }
    else
    {
        rear=rear+1;
        queue[rear]=value;
        printf("INSERTION SUCCESS");
    }
}

void dequeue()
{
    int value;
    if(rear==-1 && front==-1)
    printf("\n QUEUE IS EMPTY !!! DELETION IS NOT POSSIBLE !!!");
    else if(front==rear)
    {
        value=queue[front];
        front=rear=-1;
        printf("\n DELETE ELEMENTS IS :- %d",value);
    }
    else
    {
        value=queue[front];
        front=front+1;
        printf("\n DELETE ELEMENTS IS :- %d",value);
    }
}

void peek()
{
    if(rear==-1)
    printf("\n QUEUE IS EMPTY !!!");
    else
    {
        printf("FRONT ELEMENT IN QUEUE IS %d",queue[front]);
    }
}

void display()
{
    if(rear==-1)
    printf("\n QUEUE IS EMPTY !!!");
    else
    {
        int i;
        printf("\n QUEUE ELEMENTS ARE :- \n");
        for(i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
    }
}