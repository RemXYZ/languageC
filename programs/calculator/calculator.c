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

char Operators[][8][16] = {
    {"(",")","[","]",""},
    {"+","-",""},
    {"*","/","%",""},
    {"^","!",""},
    {"sin","cos","tg","ctg", "log","\0"},
    {'\0'}
};
int OperatorsLines = 5;
char OperatorFun[][16] = {"sin","cos","tg","ctg", "log"};
int OperatorsFunLen = 5;


dArrString splitExpr(char* expr) {
    int len = strlen(expr);
    dArrString splitedExpr;
    D_ARR_STRING(;splitedExpr);
    // char** splitedExpr = (char**) malloc(10 * sizeof(char*));
    // char splitedExpr[32][32];
    
    char varBuffer[16] = {'\0'};
    int varBufferLen = 0;
    int isVar = 0;

    for (int i = 0; i< len; i++) {
        if (isdigit(expr[i])) {
            dArrStringPushChar(&splitedExpr, expr[i]);
            continue;
        }
        //# if char is variable
        if (isalpha(expr[i])) {
            isVar = 1;
            varBuffer[varBufferLen] = expr[i];
            varBuffer[varBufferLen + 1] = '\0';
            varBufferLen++;
            // printf("%s\n", varBuffer);

            for (int j = 0; j < OperatorsFunLen; j++) {
                int funLen = strlen(OperatorFun[j]);
                //# cI = char index
                int cI = 0;
                // printf("LEN IS B:%d F:%d cB: %c, cF: %c\n", varBufferLen, funLen, varBuffer[cI], OperatorFun[j][cI]);
                while((varBuffer[cI] == OperatorFun[j][cI]) && (varBufferLen == funLen) && cI < funLen) {
                    // printf("OK %c i: %d\n", varBuffer[cI], cI);
                    cI++;
                }
                if ((cI) == funLen) {
                    dArrStringPush(&splitedExpr, varBuffer);
                    varBufferLen = 0;
                    varBuffer[varBufferLen] = '\0';
                    isVar = 0;
                }

                // //# fCI = function char index
                // for (int fCI = 0; fCI < funLen; fCI++) {
                //     //# cI = char index
                //     if (varBuffer[fCI] == OperatorFun[j][fCI]) {
                //         printf("%c is OK\n", varBuffer[fCI]);
                //     }
                    
                // }
                    
            }
            continue;
        }
        if (isVar) {
            dArrStringPush(&splitedExpr, varBuffer);
            varBufferLen = 0;
            varBuffer[varBufferLen] = '\0';
            isVar = 0;
        }
        //# THIS LOOP LOOKING FOR OPERATORS
        //# first square brackets {},
        for (int weight = 0; weight < OperatorsLines; weight++){
            //# operator index
            //# second square brackets {""}
            int operI = 0;
            while(Operators[weight][operI][0] != '\0') {
                //# third square brackets {"(",")","\0"},
                char* operator = Operators[weight][operI];
                // printf("%c lol %c is var ? %d\n",expr[i], operator[0], isVar);
                int operLen = strlen(operator);
                //# if char is operator
                if (operator[0] == expr[i]) {
                    dArrStringPushChar(&splitedExpr, operator[0]);
                }
                // printf("HI%s\n", operator);
                operI++;
                
            }
            // weight++;
        }
        // break;
    }

    //# if last element was variable
    if (varBufferLen!=0) dArrStringPush(&splitedExpr, varBuffer);

    return splitedExpr;
}


//# To reverse Polish notation function
dArrString toRPN(char* expr){
    int len = strlen(expr);
    printf("%s, LEN: %d FFFFFFFFFFFFFFFEWEFWEFWE\n\n\n\n\n", expr, len);
    

    dArrString stos;
    D_ARR_STRING(;stos);
    // char** outStr = (char**) malloc(1 * sizeof(char*));
    dArrString outStr;
    D_ARR_STRING(;outStr);
    
    dArrString splitedExpr = splitExpr(expr);
    dArrStringPrint(&splitedExpr);

    dArrStringFree(&stos);
    return outStr;
}
// expr = expression
int calculator(char* expr) {
    
    toRPN(expr);
}
