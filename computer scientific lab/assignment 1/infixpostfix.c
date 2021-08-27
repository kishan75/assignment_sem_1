#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 1000
#define push(stp, n) (*((stp)++) = (n))
#define pop(stp) (*--(stp))

int stack[MAX];

int precedence(char op){
    switch(op){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

char *infixToPostfix(char expr[], int *stp, char res[], int n){
    int i, j=0;

    for(i=0; i<n; i++){
        if((expr[i] < 40 || expr[i] > 47) && expr[i] !=94 ) // Not an operator (94='^')
            res[j++] = expr[i];

        else if(expr[i] == '(')
            push(stp, expr[i]);

        else if(expr[i] == ')'){
            while (stp!=stack && *(stp-1) != '(')
                res[j++] = pop(stp);
            pop(stp);
        }else{ // Operator
            while(stp!=stack && precedence(expr[i]) <= precedence(*(stp-1)))
                res[j++] = pop(stp);
            push(stp, expr[i]);
        }
    }

    while (stp!=stack) // Pop all from stack to res
        res[j++] = pop(stp);

	res[j] = '\0';
}

int evalPostfix(char res[], int  n, int *stp){
	int i;
	
	for(i=0; i<n && res[i]!='\0'; i++){
		if(isdigit(res[i]) == 0 && ((res[i] < 40 || res[i] > 47) && res[i] !=94)){
			printf("\n ERR: numerical expression\n");
			exit(0);
		}else if(isdigit(res[i])){
			push(stp, res[i]-'0');
		}else{
			int v = pop(stp);
			switch(res[i]) {
				case '+': 
					push(stp, pop(stp) + v);
					break;
                case '-':
                    push(stp, pop(stp) - v);
                    break;
                case '*':
                    push(stp, pop(stp) * v);
                    break;
                case '/':
                    push(stp, pop(stp) / v);
                    break;
			    case '^':
                    push(stp, pow(pop(stp), v));
                    break;
			}
		}
	}
	return *(stp-1);
}

int main(){
	int *stp = stack;
    char expr[MAX];

	printf("insert valid infix expression");
	scanf("%s", expr); // 5+7*(3^2-6)^(8+1*2)-4

    int n = strlen(expr);
    char res[n];

    infixToPostfix(expr, stp, res, n);
	printf("Postfix expression: %s\n", res); 

	int ans = evalPostfix(res, n, stp);
	printf("\nPostfix evaluation result: %d\n", ans); 

    return 0;
}
