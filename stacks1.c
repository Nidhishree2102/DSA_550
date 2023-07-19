#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct stack
{
    int data[SIZE];
    int top;
};

void push(struct stack *sptr,int element)
{
    if(sptr->top==SIZE-1)
        printf("Stack overflow\n");
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=element;
    }
}

int pop(struct stack *sptr)
{
    int element;
    if(sptr->top==-1)
        return -1;
    else
    {
        sptr->data[sptr->top]=element;
        sptr->top--;
        return element;
    }
}

int peek(struct stack *sptr)
{
    int element;
    if(sptr->top==-1)
       return -1;
    else
    {
        element=sptr->data[sptr->top];
        return element;
    }
}

void display(struct stack *sptr)
{
    int i;
    if(sptr->top==-1)
        printf("Stack empty\n");
    else
    {
        for(i=sptr->top;i!=-1;i--)
            printf("%d",sptr->data[i]);
    }
}

int main()
{
    int ch,element;
    struct stack s;
    struct stack *sptr;
    sptr=&s;
    sptr->top==1;
    while(1)
    {
        printf("Stack menu\n");
        printf("1.Push 2.Pop 3.Peek 4.Display\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to push\n");
            scanf("%d",&element);
            push(sptr,element);
            break;
            case 2:element=pop(sptr);
            if(element==-1)
                printf("Stack underflow\n");
            else
                printf("Popped %d\n",element);
                break;
            case 3:element=peek(sptr);
            if(element==-1)
                printf("Stack empty\n");
            else
                printf("Top data is %d\n",element);
                break;
            case 4:display(sptr);
                   break;
            case 5:exit(0);
            default:printf("Invalid choice\n");
                    break;
        }
    }
    return 0;
}


