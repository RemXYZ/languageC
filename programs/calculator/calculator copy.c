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

int validateSpecialFun(dString& cpecFunBuf, char a) {
    // int len = strlen(expr);
    const char specialFun[][32] = {"sin","cos","tg","ctg",'\0'};
    int varDetected = 0;
    char aStr[] = {a,'\0'};
    cpecFunBuf.cat(cpecFunBuf, aStr);
    int len = cpecFunBuf.length;
    printf("\n\nIN:[%s, %d]", cpecFunBuf.s, len);

    for (int sFi = 0; sFi < sizeof(specialFun) / sizeof(*specialFun); sFi++) {
        int j = 0;
        //# special function letter index
        int sFLi = 0;

    }
    return 0;

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

dArrString splitExpr(char* expr) {
    int len = strlen(expr);
    D_STRING_INIT(cpecFunBuf, "");

    const char emptyStr[][2] = {{""}};
    D_ARR_STRING_INIT(outStr, emptyStr);
    // # this loop is going throw char in expression
    for (int i=0; i<len; i++){
        // findWeight(expr[i]);
        int isFunChar = validateSpecialFun(cpecFunBuf, expr[i]);
        printf("\nOUT:%dd\n",isFunChar);
        printf("YES");
        printf("%s", cpecFunBuf.s);
        outStr.push(outStr,&expr[i]);
        cpecFunBuf.clear(cpecFunBuf);
        // printf("%c",expr[i]);
    }
    printf("\n\n");
    outStr.print(outStr);
    return outStr;

}

dArrString validateCalcExpr(char* expr) {
    const char emptyStr[][2] = {{""}};
    dArrString outStr;
    D_ARR_STRING(outStr, emptyStr);
    int len = strlen(expr);
    //# this loop is going throw char in expression
    for (int i=0; i<len; i++){
        
    }
    return outStr;
}


//# To reverse Polish notation function
dArrString toRPN(char* expr){
    printf("FFFFFFFFFFFFFFFEWEFWEFWE\n\n\n\n\n");
    
    
    const char emptyStr[][2] = {{""}};
    dArrString stos;
    dArrString outStr;
    D_ARR_STRING(stos, emptyStr);
    D_ARR_STRING(outStr, emptyStr);
    char specialVar[][32][16] = {"pi",'\0'};
    
    dArrString mExpr = splitExpr(expr);

    stos.free(stos);
    return outStr;
}
// expr = expression
int calculator(char* expr) {
    
    toRPN(expr);
}
