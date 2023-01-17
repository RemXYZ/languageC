// #include "../dArray.c"
#include <math.h>

char Operators[][8][16] = {
    {"(",")","\0"},
    {"+","-","\0"},
    {"*","/","%","\0"},
    {"^","\0"},
    {"sin","cos","tg","ctg", "log", "sqrt", "\0"},
    {'\0'}
};
int OperatorsLines = 5;
char OperatorFun[][16] = {"sin","cos","tg","ctg", "log", "sqrt"};


dArrString splitExpr(char* expr) {
    int len = strlen(expr);
    dArrString splitedExpr;
    D_ARR_STRING(;splitedExpr);
    // char** splitedExpr = (char**) malloc(10 * sizeof(char*));
    // char splitedExpr[32][32];
    
    char varBuffer[16] = {'\0'};
    int varBufferLen = 0;
    int isVar = 0;

    char numBuffer[16] = {'\0'};
    int numBufferLen = 0;
    int isNum = 0;

    for (int i = 0; i< len; i++) {
        if (isdigit(expr[i])) {
            isNum = 1;
            numBuffer[numBufferLen] = expr[i];
            numBuffer[numBufferLen + 1] = '\0';
            numBufferLen++;
            // dArrStringPushChar(&splitedExpr, expr[i]);
            continue;
        }
        if (isNum) {
            dArrStringPush(&splitedExpr, numBuffer);
            numBufferLen = 0;
            numBuffer[numBufferLen] = '\0';
            isNum = 0;
        }
        //# if char is variable
        if (isalpha(expr[i])) {
            isVar = 1;
            varBuffer[varBufferLen] = expr[i];
            varBuffer[varBufferLen + 1] = '\0';
            varBufferLen++;
            // printf("%s\n", varBuffer);

            for (int j = 0; j < sizeof(OperatorFun)/sizeof(*OperatorFun); j++) {
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
    if (numBufferLen!=0) dArrStringPush(&splitedExpr, numBuffer);

    return splitedExpr;
}

// void pushToStos(dArrString *stos, dArrString *stosW, dArrString *splitedExpr) {
//     dArrStringPush(stos, splitedExpr->arr[i]);
//     dArrStringPushChar(stosW, (char)weight);
// }

// void intToChar(int i, char* ch) {
//     int j = 0;
//     while(i > 0) {
//         char intCh = (i % 10) + '0';
//         ch[j] = intCh;
//         ch[j + 1] = '\0';
//         i /= 10;
//         j++;
//     }
// }

//# To reverse Polish notation function
dArrString toRPN(char* expr){
    int len = strlen(expr);
    // printf("%s, LEN: %d FFFFFFFFFFFFFFFEWEFWEFWE\n\n\n\n\n", expr, len);
    
    dArrString splitedExpr = splitExpr(expr);
    // printf("DATA\n");
    // dArrStringPrint(&splitedExpr);
    // printf("\n");

    dArrString stos;
    D_ARR_STRING(;stos);
    //# stos weight
    dArrString stosW;
    D_ARR_STRING(;stosW);
    // char** outStr = (char**) malloc(1 * sizeof(char*));
    dArrString outStr;
    D_ARR_STRING(;outStr);

    // converting to RPN
    for (int i = 0; i < splitedExpr.length; i++) {
        if (isdigit(splitedExpr.arr[i][0])) {
            dArrStringPush(&outStr, splitedExpr.arr[i]);
        }
        //# THIS LOOP LOOKING FOR OPERATORS
        //# first square brackets {},
        for (int weight = 0; weight < OperatorsLines; weight++){
            char weightCh[4];
            //# convert int to string, 
            //# more: https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
            itoa(weight, weightCh, 10);
            
            //# operator index
            //# second square brackets {""}
            int operI = 0;
            while(Operators[weight][operI][0] != '\0') {
                //# third square brackets {"(",")","\0"},
                char* operator = Operators[weight][operI];
                // printf("%c lol %c is var ? %d\n",expr[i], operator[0], isVar);
                int operLen = strlen(operator);

                //# if char is operator
                //# strcmp string compre - porównuje string, zwraca 0 jeśli są równe
                //# lub operator jest równy (
                // printf("HIII  %s NUM %s\n", operator, splitedExpr.arr[i]);
                if (!strcmp(operator, splitedExpr.arr[i])) {
                    // dArrStringPrint(&stos);
                    // printf("HELLO %s and %s\n", splitedExpr.arr[i], operator);
                    if ( (stos.length == 0) || (operator[0] == '(')) {
                        dArrStringPush(&stos, splitedExpr.arr[i]);
                        dArrStringPush(&stosW, weightCh);
                        
                    }
                    // # lub waga dwuch operatorów jest taka sama, to powinno być else if, 
                    // # bo jezeli dodam w pierwszy warunek, a stos bedzie pusty, to wyswietli sie blad
                    //# atoi convert str to int
                    //# more: https://www.geeksforgeeks.org/convert-string-to-int-in-c/
                    else if( atoi(stosW.arr[stosW.length-1]) < weight){
                        
                        dArrStringPush(&stos, splitedExpr.arr[i]);
                        dArrStringPush(&stosW, weightCh);
                    }
                    else {
                        //stI = stos index
                        int stI = stos.length-1;
                        while( (stI >= 0) && (atoi(stosW.arr[stI]) >= weight)) {
                            // printf("START --DELETE -- \nw=[%d,%d], prev op %s, my op %c, INDEX: %d\n", atoi(stosW.arr[stI]) , weight, stos.arr[stI], operator[0], stI);
                            // printf("Op %s, dla ( %d, dla ) %d, all %d\n", stosW.arr[stI], strcmp(stos.arr[stI],"("), strcmp(stos.arr[stI],")"), ((strcmp(stos.arr[stI],"(") != 0) & (strcmp(stos.arr[stI],")") != 0)));

                            if ((strcmp(stos.arr[stI],"(") != 0) & (strcmp(stos.arr[stI],")") != 0)) {
                                // printf("RGREGREGERER\n");
                                dArrStringPush(&outStr, stos.arr[stI]);
                            }
                            
                            
                            dArrStringPop(&stos, 1);
                            dArrStringPop(&stosW, 1);
                            // printf("HII\n");
                            // printf("prev op2 %d\n", stos.arr[stI][0] == '(');
                            if ( (operator[0] == ')') & (stos.arr[stI][0] == '(') ) {
                                stI = -1;
                            }

                            if ((stos.length == 0)) {
                                dArrStringPush(&stos, splitedExpr.arr[i]);
                                dArrStringPush(&stosW, weightCh);
                            }
                            else if( (atoi(stosW.arr[stosW.length-1]) < weight) ){
                                dArrStringPush(&stos, splitedExpr.arr[i]);
                                dArrStringPush(&stosW, weightCh);
                            }
                            stI--;
                            // printf("RGREGERG %d\n", stI);
                            
                        }
                    }
                    
                }
                // printf("HI%s\n", operator);
                operI++;
                
                
            }
            // weight++;
        }
    }
    int stI = stos.length-1;
    while( (stI >= 0)) {
        if ((strcmp(stos.arr[stI],"(") != 0) & (strcmp(stos.arr[stI],")") != 0)) {
            dArrStringPush(&outStr, stos.arr[stI]);
        }
        dArrStringPop(&stos, 1);
        dArrStringPop(&stosW, 1);
        stI--;
        // printf("RGREGERG %d\n", stI);
        
    }

    // // printf("\n\n\nSTOS\n");
    // dArrStringPrint(&stos);
    // // printf("STOSW\n");
    // dArrStringPrint(&stosW);
    // // printf("OUT\n");
    // dArrStringPrint(&outStr);

    dArrStringFree(&stos);
    dArrStringFree(&stosW);
    dArrStringFree(&splitedExpr);
    return outStr;
}

dString doArith(char* aStr, char* bStr, char op) {
    double a = atof(aStr);
    double b = atof(bStr);
    double arith;
    if (op == '+') {arith = a+b;}
    if (op == '-') {arith = a-b;}
    if (op == '*') {arith = a*b;}
    if (op == '/') {arith = a/b;}
    if (op == '^') {arith = pow(a,b);}
    

    printf("DO IT: %s, %s, %c RESULT: %f\n", aStr, bStr, op, arith);
    char arithStr[256];
    sprintf(arithStr, "%f", arith);
    dString outStr;
    // itoa(arith, arithStr, 10);
    D_STRING(outStr, arithStr);
    return outStr;
}

// {"sin","cos","tg","ctg", "log", "sqrt", "\0"},
dString doArithFun(char* aStr, char* op) {
    double a = atof(aStr);
    double arith = 0;
    printf("\nRGERRE op %s and %d\n",op, !strcmp(op, "sin"));
    if (!strcmp(op, "sqrt")) {arith = sqrt(a);}
    if (!strcmp(op, "sin")) {arith = sin(a);}
    if (!strcmp(op, "cos")) {arith = cos(a);}
    if (!strcmp(op, "tg")) {arith = tan(a);}
    // if (!strcmp(op, "ctg")) {arith = cot(a);}
    if (!strcmp(op, "log")) {arith = log(a);}
    

    printf("DO IT FUN : %s, %c RESULT: %f\n", aStr, op, arith);
    char arithStr[256];
    sprintf(arithStr, "%f", arith);
    dString outStr;
    // itoa(arith, arithStr, 10);
    D_STRING(outStr, arithStr);
    return outStr;
}

int calculteRPN(dArrString* rpn) {
    dArrString stos;
    D_ARR_STRING(;stos);
    int i = 0;

    // for (int i = 0; i < rpn->length; i++) {
    while( (i < 4096) ){
        dArrStringPush(&stos, rpn->arr[i]);
        // printf("LOL %d\n", i);
        dArrStringPrint(&stos);

        for (int weight = 0; weight < OperatorsLines; weight++){
            char weightCh[4];
            itoa(weight, weightCh, 10);
            
            //# operator index
            //# second square brackets {""}
            int operI = 0;
            while(Operators[weight][operI][0] != '\0') {
                //# third square brackets {"(",")","\0"},
                char* operator = Operators[weight][operI];
                // printf("%c lol %c is var ? %d\n",expr[i], operator[0], isVar);
                int operLen = strlen(operator);
                // "sin","cos","tg","ctg", "log", "sqrt"
                if (!strcmp(operator, rpn->arr[i])) {
                    // if ((operator[0] == rpn->arr[i][0]) || operator[0] = '+' || ) {
                        if (rpn->arr[i][0] == '+' \
                        || rpn->arr[i][0] == '-' \
                        || rpn->arr[i][0] == '*' \
                        || rpn->arr[i][0] == '/' \
                        || rpn->arr[i][0] == '^'
                        ) {
                        dString arith = doArith(stos.arr[stos.length-3], stos.arr[stos.length-2], rpn->arr[i][0]);
                        printf("arith %s stos: %s %s\n", arith.s, stos.arr[stos.length-3], stos.arr[stos.length-2]);
                        dArrStringPop(&stos, 3); // remove operator, // remove first number, // remove second number
                        dArrStringPush(&stos, arith.s);
                        free(arith.s);
                    }
                    // || operator == "sin"\
                    //     || operator == "cos"\
                    //     || operator == "tg"\
                    //     || operator == "ctg"\
                    //     || operator == "log"
                    if (
                        !strcmp(rpn->arr[i], "sqrt")\
                        || !strcmp(rpn->arr[i], "sin")\
                        || !strcmp(rpn->arr[i], "cos")\
                        || !strcmp(rpn->arr[i], "tg")\
                        || !strcmp(rpn->arr[i], "ctg")\
                        || !strcmp(rpn->arr[i], "log")
                    ) {
                        printf("FUUUUN %s\n", rpn->arr[i] );
                        dString arith = doArithFun(stos.arr[stos.length-2], rpn->arr[i]);
                        
                        printf("FUUUUN arith %s stos: %s %s\n", arith.s, stos.arr[0], stos.arr[1]);
                        dArrStringPop(&stos, 2); // remove operator, // remove first number, // remove second number
                        dArrStringPush(&stos, arith.s);
                        free(arith.s);
                    }
                                    
                }

                operI++;  
            }
        }
        if (i == (rpn->length-1)) {
            break;
        }
        i++;
    }
    printf("HIII RESULT:\n\n");
    dArrStringPrint(&stos);
    return 0;
}

// expr = expression
int calculator(char* expr) {
    
    dArrString rpnArr = toRPN(expr);
    dArrStringPrint(&rpnArr);
    printf("-----\n");
    calculteRPN(&rpnArr);
}
