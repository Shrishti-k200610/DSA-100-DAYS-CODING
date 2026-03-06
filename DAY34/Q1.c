#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int x){
    struct node *n=malloc(sizeof(struct node));
    n->data=x;
    n->next=top;
    top=n;
}

int pop(){
    int x=top->data;
    struct node *t=top;
    top=top->next;
    free(t);
    return x;
}

int main(){
    char exp[50];
    int a,b;

    printf("Enter postfix: ");
    scanf("%s",exp);

    for(int i=0; exp[i]; i++){
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else{
            b=pop();
            a=pop();
            if(exp[i]=='+') push(a+b);
            if(exp[i]=='-') push(a-b);
            if(exp[i]=='*') push(a*b);
            if(exp[i]=='/') push(a/b);
        }
    }

    printf("Result = %d",pop());
    return 0;
}
