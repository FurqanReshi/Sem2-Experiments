#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str[100], stack[100];
    int top=-1,i,flag=0;
    printf("Enter expression: ");
    gets(str); 
    int len=strlen(str);
    char ch;
    for(i=0; i<len; i++){
        ch=str[i];
        if(ch=='['||ch=='{'||ch=='('){
            stack[++top]=ch;
        }
        else if(ch==']'||ch=='}'||ch==')'){
            if(stack[top]=='[')
                stack[top]=']';
            else if(stack[top]=='{')
                stack[top]='}';
            else
                stack[top]=')';
            if(stack[top]==ch){
                top--;
            }
            else{
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
        printf("\nExpression is not balanced");
    else
        printf("Expression is Balanced");
    return 0;
}