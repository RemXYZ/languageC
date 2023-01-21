dInt findVarPos(dArrString* fun, char* var) {
    dInt varPos;
    D_INT(varPos);
    for (int i = 0; i < fun->length; i++) {
        if (!strcmp(fun->arr[i], var)) {
            dIntPush(&varPos, i);
        }
    }
    // dIntPrint(&varPos);
    return varPos;
}


void funSubstitution(dArrString* fun, dInt* varPos, double val){
    // dArrStringPrint(fun);
    for (int i = 0; i < varPos->length; i++){
        char valStr[256];
        sprintf(valStr, "%f", val);
        strcpy(fun->arr[varPos->arr[i]], valStr);
    }
    
}

void integral(dArrString* fun, double a, double b, double n) {
    dInt varPos = findVarPos(fun, "x");
    dArrString result;
    double sum = 0;
    // dIntPrint(&varPos);
    // printf("----\n");
    for (int i = 0; i < n; i++) {
        double val = (a + i) * ((b-a) / n);
        // printf("Fun and %f\n", val);
        funSubstitution(fun, &varPos, val);
        // dArrStringPrint(fun);
        result = calculteRPN(fun);
        sum += atof(result.arr[0]);
        // printf("Odpowiedz: %s\n\n", result.arr[0]);
    }
    //approximate result
    double approxResult = ((b-a)/n) * (sum);
    printf("Resultat: %f", approxResult);
    dArrStringFree(&result);
}