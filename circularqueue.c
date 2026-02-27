/* IN THIS WE WILL IMPLEMENT A CIRCULAR QUEUE BY USING ARRAY.*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int front=-1,rear=-1;

void enqueue(int value)
{
    if((rear+1)%SIZE==front)
    {
        printf("QUEUE IS FULL!\n");
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        queue[rear]=value;
        printf("INSERTION SUCCESS.");
    }
    else
    {
        rear=(rear+1)%SIZE;
        queue[rear]=value;
        printf("INSERTION SUCCESS.");
    }
}

void dequeue()
{
    int val;
    if(front==-1)
    {
        printf("QEUEUE IS EMPTY!\n");
    }
    else if(front==rear)
    {
        val=queue[front];
        front=-1;
        rear=-1;
        printf("DELETED ELEMENTS FROM QUEUE IS %d",val);
    }
    else
    {
        val=queue[front];
        front=(front+1)%SIZE;
        printf("DELETED ELEMENTS FROM QUEUE IS %d",val);
    }
}

void peek()
{
    if(front==-1)
    {
        printf("QUEUE IS EMPTY !\n");
    }
    else
    {
        printf("FRONT ELEMENT IS %d\n",queue[front]);
    }
}

void display()
{
    if(front==-1)
    {
        printf("QUEUE IS EMPTY !\n");
        return;
    }
    printf("QUEUE ELEMENTS :- ");
    int i=front;

    while(1)
    {
        printf("%d",queue[i]);
        if(i==rear)
        break;
        i=(1+i)%SIZE;
    }
    printf("\n");
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.PEEK\n 5.EXIT\n\n");
        printf("ENTER YOUR CHOICE :- ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("ENTER VALUE TO ENQUEUE :- ");
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
            return 0;

            default :
            printf("INVALID CHOICE !\n");
        }
    }
}