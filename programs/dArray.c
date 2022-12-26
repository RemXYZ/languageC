// more about typdef: https://riptutorial.com/c/example/31818/typedef-for-function-pointers
// more about how to use this: https://stackoverflow.com/questions/5815340/get-the-pointer-of-struct-calling-function
// well in c I can't use objects ;_;
// #define GET_TYPE(X) ((X)->GetType((X)))
typedef struct dCharArray
{
    char* a;
    int maxLength;
    int length;
    void (*set)(dCharArray&, const char*);
    void (*cat)(dCharArray&, const char*);
    void (*pop)(dCharArray&, int);
} dCharArray;


void dCharArraySet(dCharArray &arr, const char* str) {
    int strLength = strlen(str);
    printf("First init: %s,%d\n", str, strLength);

    // worke with array memory
    int doRealloc = 0;
    if (arr.maxLength <= strLength)
    while (arr.maxLength <= strLength){
        arr.maxLength *= 2;
        doRealloc = 1;
    }
    if (doRealloc) arr.a = (char*) realloc(arr.a, arr.maxLength * sizeof(char*));

    printf("Second l:%d dorealoc?: %d\n",arr.maxLength, doRealloc);

    arr.length = strLength;
    // strcpy(arr.a, str);
    // copy string instead cpystr, but work like cpystr
    for (int i=0; i < arr.length; i++){
        arr.a[i] = str[i];
    }
    arr.a[arr.length] = '\0';
    printf("\nMy text: %s", arr.a);
}

void dCharArrayConcat(dCharArray &arr, const char* str) {
    int strLength = strlen(str);
    int newStrLength = arr.length + strLength;
    // worke with array memory
    int doRealloc = 0;
    if (arr.maxLength <= strLength)
    while (arr.maxLength <= strLength){
        arr.maxLength *= 2;
        doRealloc = 1;
    }
    if (doRealloc) arr.a = (char*) realloc(arr.a, arr.maxLength * sizeof(char*));

    for (int i=0; i < (newStrLength - arr.length); i++){
        arr.a[arr.length + i] = str[i];
        // printf("Char:%c i:%d.  ",arr.a[arr.length + i], i);
    }
    // set new length
    arr.length = newStrLength;
    arr.a[arr.length] = '\0';

    printf("\nCat word, %s, Str after cat %s, L after cat:%d dorealoc?: %d\n",str, arr.a, arr.maxLength, doRealloc);

}

void dCharArrayPop(dCharArray &arr, int howLong) {
        // printf("[Len: %i, Ch: %c]\n",arr.length, arr.a[arr.length - 2]);
    for (int i = 1; i <= howLong; i++) {
        // printf("[%c and %i]\n",arr.a[arr.length-i], i);
        arr.a[arr.length - i] = 0;
    }
    arr.length -= howLong;
    printf("\nRGrgrg\n");
    
}

// more about macro: https://www.youtube.com/watch?v=JqN4uVgCTWE&ab_channel=CodeVault
// more about "templates" in c: https://www.youtube.com/watch?v=u2ey-ERC_A0&ab_channel=LearnThenTeach
// const char* D_ARR_STRING_##NAME##_BUFFER = STRING; // buffer string. It looks like var_NAME_var, could be usefull in the future.
// D - dinamic, ARR - array, D_ARR -  dinamic array
#define D_ARR_STRING(NAME, STRING)\
    dCharArray NAME = {(char*) malloc(0 * sizeof(char*)), 2, 0, dCharArraySet, dCharArrayConcat, dCharArrayPop};\
    NAME.set(NAME, STRING);\

// #define D_ARR_INT(NAME)
//     dCharArray #NAME = {(char*) malloc(0 * sizeof(char*)), 0, dCharArrayPush, po};
