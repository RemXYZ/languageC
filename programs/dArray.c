// more about typdef: https://riptutorial.com/c/example/31818/typedef-for-function-pointers
// more about how to use this: https://stackoverflow.com/questions/5815340/get-the-pointer-of-struct-calling-function
// well in c I can't use objects ;_;
// #define GET_TYPE(X) ((X)->GetType((X)))
typedef struct dString
{
    char* s;
    int maxLength;
    int length;
}dString;


void dStringSet(dString *arr, const char* str) {

    int strLength = strlen(str);
    // printf("First init: %s,%d\n", str, strLength);

    // worke with array memory
    int doRealloc = 0;
    if (arr->maxLength <= strLength)
    while (arr->maxLength <= strLength){
        arr->maxLength *= 2;
        doRealloc = 1;
    }
    if (doRealloc) arr->s = (char*) realloc(arr->s, arr->maxLength * sizeof(char*));

    // printf("Second l:%d dorealoc?: %d\n",arr->maxLength, doRealloc);

    arr->length = strLength;
    // strcpy(arr->s, str);
    // copy string instead cpystr, but work like cpystr
    for (int i=0; i < arr->length; i++){
        arr->s[i] = str[i];
    }
    arr->s[arr->length] = '\0';
    // printf("\nMy text: %s", arr->s);
}

void dStringConcat(dString *arr, const char* str) {
    // printf("\nSTR%s\n",str);
    int strLength = strlen(str);
    int newStrLength = arr->length + strLength;
    // work with array memory
    int doRealloc = 0;
    if (arr->maxLength <= strLength)
    while (arr->maxLength <= strLength){
        arr->maxLength *= 2;
        doRealloc = 1;
    }
    if (doRealloc) arr->s = (char*) realloc(arr->s, arr->maxLength * sizeof(char*));

    for (int i=0; i < (newStrLength - arr->length); i++){
        arr->s[arr->length + i] = str[i];
        // printf("Char:%c i:%d.  ",arr->s[arr->length + i], i);
    }
    // set new length
    arr->length = newStrLength;
    arr->s[arr->length] = '\0';

    // printf("\nCat word, %s, Str after cat %s, L after cat:%d dorealoc?: %d\n",str, arr->s, arr->maxLength, doRealloc);

}

void dStringPop(dString *arr, int howLong) {
        // printf("[Len: %i, Ch: %c]\n",arr->length, arr->s[arr->length - 2]);
    for (int i = 1; i <= howLong; i++) {
        // printf("[%c and %i]\n",arr->s[arr->length-i], i);
        arr->s[arr->length - i] = '\0';
    }
    arr->length -= howLong;
    // printf("\nRGrgrg\n");
    
}
void dStringClear(dString *arr) {
    arr->s[0] = '\0';
    arr->length = 0;
}

// more about macro: https://www.youtube.com/watch?v=JqN4uVgCTWE&ab_channel=CodeVault
// more about "templates" in c: https://www.youtube.com/watch?v=u2ey-ERC_A0&ab_channel=LearnThenTeach
// const char* D_ARR_STRING_##NAME##_BUFFER = STRING; // buffer string. It looks like var_NAME_var, could be usefull in the future.
// D - dinamic, ARR - array, D_ARR -  dinamic array

#define D_STRING(NAME, STRING)\
    NAME.s = (char*) malloc(2 * sizeof(char*));\
    NAME.maxLength = 2;\
    NAME.length = 0;\
    dStringSet(&NAME, STRING);

#define D_STRING_INIT(NAME, STRING)\
    dString NAME;\
    D_STRING(NAME, STRING);




typedef struct dArrString
{
    char** arr;
    int maxLength;
    int length;
} dArrString;

void dArrStringPush(dArrString *arr, const char* str) {
    // printf("\n%s STRING PUSH \n", str);
    int strLength = strlen(str);
    // printf("\nLOOK:%s, %d\n", str, strLength);
    arr->arr[arr->length] = (char*) malloc((strLength+1) * sizeof(char*));


    //# 2D REALLOC DON'T WORK
    // int binLength = 2;
    // REALLOC TO MAIN ARRAY
    // int doRealloc = 0;
    // while (arr->maxLength < (arr->length+1)) {
    //     arr->maxLength *= 2;
    //     doRealloc = 1;
    // }
    // printf("%c and %d\n", str[0], arr->maxLength);
    // if (doRealloc) arr->arr = (char*) realloc(arr->arr, arr->maxLength * sizeof(char*));
    

    //# WORK SIMULAR TO STRCPY
    // for (int i=0; i < strLength; i++){
    //     arr->arr[arr->length][i] = str[i];
    // }
    // arr->arr[arr->length][strLength] = '\0';
    strcpy(arr->arr[arr->length], str);
    arr->length++;
}

void dArrStringPushChar(dArrString *arr, char oneChar) {
    // printf("\n%cHIIII\n", oneChar);
    const char bufferChar[] = {oneChar, '\0'};
    dArrStringPush(arr, bufferChar);
}

void dArrStringPushCharPtr(dArrString *arr, char oneChar) {
    // printf("\n%cHIIII\n", oneChar);
    const char bufferChar[] = {oneChar, '\0'};
    dArrStringPush(arr, bufferChar);
}

void dArrStringPop(dArrString *arr, int howLong) {
        // printf("[Len: %i, Ch: %c]\n",arr->length, arr->s[arr->length - 2]);
    for (int i = 1; i <= howLong; i++) {
        // printf("[%c and %i]\n",arr->s[arr->length-i], i);
        free(arr->arr[arr->length - i]);
        // arr->arr[arr->length - i] = 0;
    }
    arr->length -= howLong;

}
void dArrStringFree(dArrString *arr) {
    dArrStringPop(arr,arr->length);
    free(arr->arr);

}

void dArrStringPrint(dArrString *arr) {
    printf("[~Array length: %d~]\n",arr->length);
    for(int i = 0; i < arr->length; i++) {
        printf("[Index:%d, String: %s]\n",i,arr->arr[i]);
    }
    
}

// more about string array with malloc: https://www.youtube.com/watch?v=4_2BEgOFd0E&ab_channel=PortfolioCourses
// D - dinamic, ARR - array, D_ARR -  dinamic array
    // dArrString NAME = {(char*) malloc(0 * sizeof(char*)), 2, 0, dArrStringSet, dArrStringConcat, dArrStringPop};
#define D_ARR_STRING(NAME)\
    NAME.arr = (char**) malloc(4096 * sizeof(char*))\
    NAME.maxLength = 4096;\
    NAME.length = 0;\
    


#define D_ARR_STRING_INIT(NAME)\
    dArrString NAME;\
    // D_ARR_STRING(NAME, ARR_STRING);

