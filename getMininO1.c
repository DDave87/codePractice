#include <stdio.h>
#include <string.h>
#define MAXSIZE 10

struct stack
{
    int stk[MAXSIZE];
    int top;
}; 
struct stack s,m;


void push (struct stack *T, int n)
{
    struct stack temp;
    temp = *T;
   // printf("\nElement %d\n",n);
    int y;
	if (temp.top == (MAXSIZE - 1))
	{
		printf ("Stack is Full\n");
		return;
	}
	else
	{
        temp.top = temp.top + 1;
        temp.stk[temp.top] = n;
	}
    //printf("Top index %d\n",temp.top);
    *T=temp;
	return;
}
int pop(struct stack *T){
    int y;
    struct stack temp;
    temp = *T;
    
    if (temp.top == - 1)
    {
		printf ("Stack is Empty\n");
        *T=temp;
		return -1;
	}
	else
	{
        y=temp.stk[temp.top];
		temp.top = temp.top - 1;
        *T=temp;
	    return(y);
	}
     
}

void specialPush(int num){
    int y;
    if (s.top == (MAXSIZE - 1))
    {
		printf ("Stack is Full\n");
		return;
	}
    else if(s.top == -1) //empty stacks
    {
            //printf("\nFirst time called for %d",num);
            push(&s,num);
            push(&m,num);
            //printf("\nFirst time Ended");
            //pushing num in both stack
    }
    else{//if stack is having elements
        y = pop(&m);//pop top to compare
        push(&m,y); //push again top element
    
        if(num>y){
            //printf("pop if called %d",y);
            push(&m,y);
            push(&s,num);
        }
        else{
           // printf("pop if called");
            push(&m,num);
            push(&s,num);
        }
    }
}

int getMin(){
int y;
y = pop(&m);
//printf("poped%d\n",y);
push(&m,y);
return y;
}

void display (struct stack *T)
{
    struct stack temp;
    temp = *T;
    int i;
	if (temp.top == -1)
	{
		printf ("Stack is empty\n");
		return;
	}
	else
	{
		printf ("\nThe status of the stack is\n");
		for (i = temp.top; i >= 0; i--)
		{
			printf ("%d\n", temp.stk[i]);
		}
	}
	printf ("\n");
     *T=temp;
}

int main()
{
    s.top = -1;
    m.top = -1;

    specialPush(10);
    specialPush(5);
    specialPush(20);
    specialPush(30);
    printf("\nAfter 10,5,20,30\n");
    display(&m);
    printf("Min->%d\n",getMin());
    
    printf("After 10,5,20,30,1 \n");
    specialPush(1);
    display(&m);
    printf("Min->%d\n",getMin());
    return 0;

}