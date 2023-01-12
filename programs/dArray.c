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
    // worke with array memory
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
    NAME.s = (char*) malloc(0 * sizeof(char*));\
    NAME.maxLength = 2;\
    NAME.length = 0;\
    dStringSet(&NAME, STRING);

#define D_STRING_INIT(NAME, STRING)\
    dString NAME;\
    D_STRING(NAME, STRING);









typedef struct dArrString
{
    char** arr;
    int locLength;
    int length;
} dArrString;

void dArrStringPush(dArrString *arr, const char* str) {
    int strLength = strlen(str);
    // printf("\nLOOK:%s, %d\n", str, strLength);
    arr->arr[arr->length] = (char*) malloc((strLength+1) * sizeof(char*));
    // printf("\nSTRMAIN:%s, LEN:%d, arrl:%d",str, strLength, arr->length);
    // for (int i=0; i < strLength; i++){
    //     arr->arr[arr->length][i] = str[i];
    // }
    // arr->arr[arr->length][strLength] = '\0';
    strcpy(arr->arr[arr->length], str);

    arr->length++;
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
    // arr->pop(arr,arr->length);
    // free(arr->arr);
}
void dArrStringPrint(dArrString *arr) {
    for(int i = 0; i < arr->length; i++) {
        printf("[Index:%d, String: %s]\n",i,arr->arr[i]);
    }
    
}

// more about string array with malloc: https://www.youtube.com/watch?v=4_2BEgOFd0E&ab_channel=PortfolioCourses
// D - dinamic, ARR - array, D_ARR -  dinamic array
    // dArrString NAME = {(char*) malloc(0 * sizeof(char*)), 2, 0, dArrStringSet, dArrStringConcat, dArrStringPop};
#define D_ARR_STRING_PARENT(NAME, ARR_STRING)\
    


#define D_ARR_STRING(NAME, ARR_STRING)\
    NAME.arr = (char**) malloc(0 * sizeof(char*))\
    NAME.locLength = 2;\
    NAME.length = 0;\
    for (int i=0; i < sizeof(ARR_STRING)/sizeof(ARR_STRING[0]);i++)\
        if (ARR_STRING[i][0] != '\0')\
            dArrStringPush(&NAME, ARR_STRING[i]);
    


#define D_ARR_STRING_INIT(NAME, ARR_STRING)\
    dArrString NAME;\
    D_ARR_STRING(NAME, ARR_STRING);
