// to reverse Polish notation
dCharArray toRPN(char* expr){
    printf("FFFFFFFFFFFFFFFEWEFWEFWE\n\n\n\n\n");
    // operator, and weight is an index
    char operatorS[][32][128] = {
        {"(",")","[","]","\0"},
        {"+","-","\0"},
        {"*","/","%","\0"},
        {"^","!","\0"},
        {"log","sin","cos","tg","ctg","\0"},
        {'\0'}
    };
    int operatorLen = 5;
    printf("\n\nD:%d", operatorLen);
    int len = strlen(expr);
    D_ARR_STRING(stos, "");
    D_ARR_STRING(outStr, "");
    printf("\n\nSTOS:%s", stos.s);
    return outStr;
    // # this loop is going throw char in string
    for (int i=0; i<len; i++){
        //# this loop is going throw lines in weight
        for (int oLine = 0; oLine < operatorLen; oLine++) {


            // DOES NOT WORK HERE
            int oLineLen = 0;
            while (operatorS[oLine][oLineLen][0] != '\0') {
                printf("\nCHAR:%c", operatorS[oLine][oLineLen][0]);
                oLineLen++;
            }
            // int oLineLen = 2;
            //# this loop is going throw columns(symbols) in weight
            for (int oCol = 0; oCol < oLineLen; oCol++) {
                printf("\nChar: %c", operatorS[oLine][oCol][0]);
            }
        }
            
    }
    free(stos.s);
    return outStr;
}
// expr = expression
int calculator(char* expr) {
    
    toRPN(expr);
}
