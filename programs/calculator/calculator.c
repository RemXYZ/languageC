char findWeight(char* sym) {
    // operators, and weight is an index
    char operatorS[][32][128] = {
        {"(",")","[","]","\0"},
        {"+","-","\0"},
        {"*","/","%","\0"},
        {"^","!","\0"},
        {"log","sin","cos","tg","ctg","\0"},
        {'\0'}
    };
    int operatorLen = 5;
    //# this loop is going throw lines in weight
    //# oLine is a weight
    for (int oLine = 0; oLine < operatorLen; oLine++) {
        //# this loop is going throw columns(symbols) in weight
        int oCol = 0;
        while (operatorS[oLine][oCol][0] != '\0') {
            // printf("\nCHAR:%c", operatorS[oLine][oLineLen][0]);
            char* operatorStr = operatorS[oLine][oCol];
            int operatorLen = strlen(operatorStr);
            for (int i = 0; i < operatorLen; i++){

            }
            printf("\nChar: %c", operatorS[oLine][oCol][0]);
            oCol++;
        }
    }    
    
}
// to reverse Polish notation
dString toRPN(char* expr){
    printf("FFFFFFFFFFFFFFFEWEFWEFWE\n\n\n\n\n");
    
    int len = strlen(expr);
    D_STRING(stos, "");
    D_STRING(outStr, "");
    printf("\n\nSTOS:%s", stos.s);
    
    // # this loop is going throw char in expression
    for (int i=0; i<len; i++){
        
    }


    free(stos.s);
    return outStr;
}
// expr = expression
int calculator(char* expr) {
    
    toRPN(expr);
}
