// #include "../dArray.c"
char Operators[][32][128] = {
    {"(",")","[","]","\0"},
    {"+","-","\0"},
    {"*","/","%","\0"},
    {"^","!","\0"},
    {"sin","cos","tg","ctg","\0"},
    {'\0'}
};


char findWeight(char* sym) {
    // Operators, and weight is an index
    int operatorLen = 5;
    //# this loop is going throw lines in weight
    //# oLine is a weight
    for (int oLine = 0; oLine < operatorLen; oLine++) {
        //# this loop is going throw columns(symbols) in weight
        int oCol = 0;
        while (Operators[oLine][oCol][0] != '\0') {
            // printf("\nCHAR:%c", Operators[oLine][oLineLen][0]);
            char* operatorStr = Operators[oLine][oCol];
            int operatorLen = strlen(operatorStr);
            for (int i = 0; i < operatorLen; i++){

            }
            printf("\nChar: %c", Operators[oLine][oCol][0]);
            oCol++;
        }
    }    
    
}

char* validateSpecialFun(char a) {
    // int len = strlen(expr);
    const char specialFun[][32] = {"sin","cos","tg","ctg",'\0'};
    //# special function buffer
    // D_STRING(cpecFunBuf, "");
    char*cpecFunBuf = (char*) malloc(0 * sizeof(char*));
    int varDetected = 0;

    // //# THIS LOOP WILL FIND OUT IS STRING HAS SPECIAL FUNCTION
    // //# specFun index
    // for (int sFi = 0; sFi < sizeof(specialFun) / sizeof(*specialFun); sFi++) {
    //     // cpecFunBuf.clear(cpecFunBuf);
    //     cpecFunBuf[0] = '\0';
    //     varDetected = 0;
    //     int j = i;
    //     //# special function letter index
    //     int sFLi = 0;
    //     while ((expr[j] == specialFun[sFi][sFLi]) && (j < len)) {
    //         varDetected = 1;
    //         // cpecFunBuf.cat(cpecFunBuf, &specialFun[sFi][sFLi]);
    //         cpecFunBuf[sFLi] = specialFun[sFi][sFLi];
    //         j++;
    //         sFLi++;
    //     }
    //     cpecFunBuf[sFLi] = '\0';
    //     for (int q = 0; q < strlen(specialFun[sFi]); q++) {
    //         if (cpecFunBuf[q] != specialFun[sFi][q]){
    //             varDetected = 0;
    //         }
    //     }
    //     printf("\n%d [%s, fun %s] is var %i",i,cpecFunBuf, specialFun[sFi], varDetected);
    // }
    // return cpecFunBuf;
}

char validateCalcExpr(char* expr) {
    int len = strlen(expr);
    //# this loop is going throw char in expression
    for (int i=0; i<len; i++){

    }
}


//# To reverse Polish notation function
dArrString toRPN(char* expr){
    printf("FFFFFFFFFFFFFFFEWEFWEFWE\n\n\n\n\n");
    
    int len = strlen(expr);
    const char emptyStr[][2] = {{""}};
    dArrString stos;
    dArrString outStr;
    D_ARR_STRING(stos, emptyStr);
    D_ARR_STRING(outStr, emptyStr);
    
    char specialVar[][32][16] = {"pi",'\0'};
    
    // # this loop is going throw char in expression
    for (int i=0; i<len; i++){
        // findWeight(expr[i]);
        validateSpecialFun(expr[i]);
        
        printf("%c",expr[i]);
    }


    stos.free(stos);
    return outStr;
}
// expr = expression
int calculator(char* expr) {
    
    toRPN(expr);
}
