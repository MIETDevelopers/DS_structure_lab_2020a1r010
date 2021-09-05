#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
struct Stack
{
    int top;    
    int size; 
    char *arr; 
};
int isFull(struct Stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct Stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
void push(struct Stack *st, char ch)
{
    if (isFull(st))
    {
       printf("Stack Overflow!!\n");
    }
    st->arr[++st->top] = ch;
}
int pop(struct Stack *st)
{
    char val;
    if (isEmpty(st))
    {
        printf("Stack is empty!!!\n");
        printf("ERROR!!\n");
        return('\0');
    }
    else{
        val = st->arr[st->top];
        st->top--;
        return val;
    }
    
}
int main()
{
    int expSize, i, ret;
    char exp[30];
    struct Stack sp;
    sp.top = -1;                    
    
    printf("Enter the expression : \n");
    gets(exp);                   
    expSize = strlen(exp);    
    sp.size = expSize;       
    sp.arr = (char *)malloc(sp.size * sizeof(char));
    for (i = 0; i < expSize; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&sp, exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if ((sp.arr[sp.top] == '(' && exp[i] == ')') || (sp.arr[sp.top] == '{' && exp[i] == '}') || (sp.arr[sp.top] == '[' && exp[i] == ']'))  //Thank you Aditya Kotwal for this part
            {
                ret = pop(&sp);
            }
            else
            {
                printf("This expression is NOT BALANCED!!! \n");
                return 0;
            }    
        }
    }
    if (isEmpty(&sp))
    {
        printf(" This expression is BALANCED!! \n");
    }
    else
    {
        printf("This expression is NOT BALANCED!! \n");
    }
    return 0;
}
