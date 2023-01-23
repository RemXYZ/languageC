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