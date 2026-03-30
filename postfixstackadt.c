/* IN THIS THE EVALUTION OF POSTFIX EXPRESSIONS USING STACK ADT IS GIVEN. */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50

float st[MAX];
int top=-1;

void push(float st[],float val)
{
    if(top==MAX-1)
    printf("\n STACK OVERFLOW.\n");
    else
    {
        top++;
        st[top]=val;
    }
}

float pop(float st[])
{
    float val=-1;
    if(top==-1)
    printf("\n STACK UNDERFLOW. \n");
    else
    {
        val=st[top];
        top--;
    }
    return val;
}

float evalutepostfixexp(char exp[])
{
    int i=0;
    float op1,op2,value;
    while(exp[i]!='\0' && exp[i]!='\n')
    {
        if(isdigit(exp[i]))
        {
            push(st,(float)(exp[i]-'0'));
        }
        else if(exp[i] !=' ')
        {
            op2=pop(st);
            op1=pop(st);

            switch(exp[i])
            {
                case'+' :
                value=op1+op2;
                break;

                case '-' : 
                value=op1-op2;
                break;

                case '/' :
                value=op1/op2;
                break;

                case '*' :
                value=op1*op2;
                break;

                case '%' :
                value=(int)op1%(int)op2;
                break;

                default :
                printf("\n INVALID OPERATOR :%c\n",exp[i]);
                exit(1);
           }
           push(st,value);
        }
        i++;
    }
    return pop(st);
}

int main()
{
    float val;
    char exp[50];
    printf("\n ENTER ANY POSTFIX EXPRESSIONS : ");
    fgets(exp,sizeof(exp),stdin);
    val=evalutepostfixexp(exp);
    printf("\n VALUE OF THE POSTFIX EXPRESSIONS = %f\n",val);
    return 0;
}