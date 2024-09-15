#include<stdio.h>
#include<stdlib.h>

char stake[50];
char output[20];
char input[20];
int top=-1;
int out=0;

char pop()
{
    if(top==-1)
        return '0';
    else
    {
        char ch=stake[top];
        top--;
        return ch;
    }
}

void push(int num)
{
    if(top<49)
    {
        top++;
        stake[top]==num;
    }
}

int isOperand(char c)
{
    if(c>=0 && c<=9)
    {
        return 1;
    }
}

int isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')')
    {
        return 1;
    }
}

void main()
{
    printf("Enter the infix expression");
    scanf("%s", input);

    for(int i=0; input[i]!='\0'; i++)
    {
        if(isOperand(input[i])==1)
        {
            push(input[i]);
        }
        else if(isOperator(input[i])==1)
        {
            if(input[i]=='+' || input[i]=='-')
            {
                if(stake[top]=='*' || stake[top]=='/' || stake[top]=='^' || stake[top]=='+' || stake[top]=='-')
                {
                    char x=pop();
                    if(x!='0')
                        output[out]=x;
                    out++;
                }
            }
            else if(input[i]=='^')
            {
                push('^');
            }
            else if(input[i]=='*' || input[i]=='/')
            {
                if(stake[top]=='+' || stake[top]=='-')
                {
                    char x=pop();
                    if(x!='0')
                        output[out]=x;
                    out++;
                }
            }
        }
    }
}