#include<stdio.h>

void insertElement(int arr[],int *n,int value,int pos)
{
    int i;
    if(pos>*n+1 || pos<1)
    {

        printf("INVALID POSITION FOR INSERTION :- ");
        return ;
    }
    for(i=*n;i>=pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    (*n)++;
}

void deleteElement(int arr[],int *n,int pos)
{
    int i;
    if(pos>*n || pos<1)
    {
        printf("INVALID POSITION FOR DELETION.");
        return;
    }
    for(i=pos-1;i<*n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    (*n)--;
}

int main()
{
    int arr[10];
    int i,value,pos,n=7;
    printf("ENTER 7 ELEMENTS :- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",& arr[i]);
    }
    printf("ENTER ELEMENTS TO INSERT :- ");
    scanf("%d",&value);
    printf("ENTER POSITION (1 TO %d) :- ",n+1);
    scanf("%d",&pos);

    insertElement(arr,&n,value,pos);
    printf("ARRAY AFTER INSERTION :- ");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
    printf("\n");
    printf("ENTER POSITION TO DELETE (1 TO %d) :-",n);
    scanf("%d",&pos);

    deleteElement(arr,&n,pos);
    printf("ARRAY AFTER DELETION :- ");
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
    printf("\n");
    return 0;
}