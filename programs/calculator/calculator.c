// #include "../dArray.c"
#include <math.h>

#define MAX_STACK_SIZE 100
#define MAX_TOKEN_LEN 50

double stack[MAX_STACK_SIZE];
int stack_top = -1;

void push(double x) {
    stack[++stack_top] = x;
}

double pop() {
    return stack[stack_top--];
}

double peek() {
    return stack[stack_top];
}

int is_operator(char *token) {
    return (
        strcmp(token, "+") == 0 ||
        strcmp(token, "-") == 0 ||
        strcmp(token, "*") == 0 ||
        strcmp(token, "/") == 0 ||
        strcmp(token, "^") == 0 ||
        strcmp(token, "sin") == 0 ||
        strcmp(token, "cos") == 0 ||
        strcmp(token, "tan") == 0 ||
        strcmp(token, "cot") == 0 ||
        strcmp(token, "sqrt") == 0
    );
}

double perform_operation(char *token) {
    double x, y;
    if (strcmp(token, "+") == 0) {
        return pop() + pop();
    } else if (strcmp(token, "-") == 0) {
        y = pop();
        x = pop();
        return x - y;
    } else if (strcmp(token, "*") == 0) {
        return pop() * pop();
    } else if (strcmp(token, "/") == 0) {
        y = pop();
        x = pop();
        return x / y;
    } else if (strcmp(token, "^") == 0) {
        y = pop();
        x = pop();
        return pow(x, y);
    } else if (strcmp(token, "sin") == 0) {
        return sin(pop());
    } else if (strcmp(token, "cos") == 0) {
        return cos(pop());
    } else if (strcmp(token, "tan") == 0) {
        return tan(pop());
    } else if (strcmp(token, "cot") == 0) {
        return 1.0/tan(pop());
    } else if (strcmp(token, "sqrt") == 0) {
        return sqrt(pop());
    } else {
        printf("Error: Invalid operator %s\n", token);
        exit(1);
    }
}

void eval_rpn(char *expression) {
    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (!is_operator(token)) {
            push(atof(token));
        } else {
            push(perform_operation(token));
        }
        token = strtok(NULL, " ");
    }
    printf("Result: %lf\n", pop());
}

char Operators[][32][128] = {
    {"(",")","[","]","\0"},
    {"+","-","\0"},
    {"*","/","%","\0"},
    {"^","!","\0"},
    {"sin","cos","tg","ctg", "log","\0"},
    {'\0'}
};

//# To reverse Polish notation function
char** toRPN(char* expr){
    printf("%s FFFFFFFFFFFFFFFEWEFWEFWE\n\n\n\n\n", expr);
    int len = strlen(expr);
    
    char** stos = (char**) malloc(1 * sizeof(char*));
    stos[0][0] = '\0';
    char** outStr = (char**) malloc(1 * sizeof(char*));
    stos[0][0] = '\0';
    // char** splitedExpr = (char**) malloc(10 * sizeof(char*));
    char splitedExpr[32][32];
    
    for (int i = 0; i< len; i++) {
        int weight = 0;
        while(Operators[weight][0][0] != '\0') {
            // operator index
            int operI = 0;
            while(Operators[weight][operI][0] != '\0') {
                char* operator = Operators[weight][operI];
                int operLen = strlen(operator);
                
                printf("HI%s\n", operator);
                operI++;
            }
            weight++;
        }
        break;
    }

    free(stos);
    return outStr;
}
// expr = expression
int calculator(char* expr) {
    
    toRPN(expr);
}
