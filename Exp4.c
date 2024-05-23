#include<stdio.h>
#include<string.h>
int top1=-1, top2=-1;
char operator[100];
int operand[100];
void process(){
    int x = operand[top1--];
    int y = operand[top1--];
    char op = operator[top2--];
    int z;
    switch(op){
        case '+':
            z=x+y;
            break;
        case '-':
            z=y-x;
            break;
        case '*':
            z=x*y;
            break;
        case '/':
            z=y/x;
            break;
    }
    operand[++top1]=z;
}
int precedence(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
int evalInfixExpression(char *str){
    int i;
    for(i=0; str[i]!='\0'; i++){
        char ch = str[i];
        if(ch>=48 && ch <=57)
            operand[++top1]=ch-48;
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            if(top2==-1)
                operator[++top2]=ch;
            else{
                while(top2!=-1 && precedence(ch)<=precedence(operator[top2])){
                    process();
                }
                operator[++top2]=ch;
            }
        }
        else if(ch=='('){
            operator[++top2]=ch;
        }
        else if(ch==')'){
            while(operator[top2]!='('){
                process();
            }
            top2--;
        }
    }
    while(top2!=-1){
        process();
    }
    return operand[top1--];
}
int evalPostfixExpression(char *str){
    int i;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]>=48 && str[i]<=57){
            operand[++top1]=str[i]-48;
        }
        else if(str[i]==' ' || str[i] == '\n')
            continue;
        else{
            int x=operand[top1--], y=operand[top1--];
            int z;
            switch(str[i]){
                case '+':
                    z=x+y;
                    break;
                case '-':
                    z=y-x;
                    break;
                case '*':
                    z=x*y;
                    break;
                case '/':
                    z=y/x;
                    break;
            }    
            operand[++top1]=z;    
        }
    }
    return operand[top1--];
}
int evalPrefixExpression(char *str){
    int i;
    for(i=strlen(str)-1; i>=0; i--){
        if(str[i]>=48 && str[i]<=57){
            operand[++top1]=str[i]-48;
        }
        else if(str[i]==' ' || str[i] == '\n')
            continue;
        else{
            int x=operand[top1--], y=operand[top1--];
            int z;
            switch(str[i]){
                case '+':
                    z=x+y;
                    break;
                case '-':
                    z=y-x;
                    break;
                case '*':
                    z=x*y;
                    break;
                case '/':
                    z=y/x;
                    break;
            }    
            operand[++top1]=z;    
        }
    }
    return operand[top1--];
}
int main(){
    char str[100];
    printf("Enter the infix expression: ");
    gets(str);
    int result = evalInfixExpression(str);
    printf("Result of Expression %s : %d\n",str,result);
    
    printf("Enter the postfix expression: ");
    gets(str);
    result= evalPostfixExpression(str);
    printf("Result of Expression %s : %d\n",str,result);

    printf("Enter the prefix expression: ");
    gets(str);
    result= evalPrefixExpression(str);
    printf("Result of Expression %s : %d\n",str,result);
    return 0;
}