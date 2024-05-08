#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

inToPost(){
    char symbol;
    for(int i=0; i<strlen(infix); i++){
        symbol=infix[i];
        switch(symbol){
            case '(':
            push(symbol);
            break;
            case ')':
            while
        }
    }
}

int main(){
    printf("Enter the infix expression : ");
    gets(infix);

    inToPost();
}