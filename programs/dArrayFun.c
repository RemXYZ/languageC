int getArrStringLen(char** arr) {
    int i = 0;
    while (arr[i][0] != '\0') {
        i++;
    }
    return i - 1;
}

void arrStringPop(char** arr, int howLong) {
    int arrLen = getArrStringLen(arr);
        // printf("[Len: %i, Ch: %c]\n",arr.length, arr.s[arr.length - 2]);
    for (int i = 1; i <= howLong; i++) {
        // printf("[%c and %i]\n",arr.s[arr.length-i], i);
        free(arr[arrLen - i]);
        // arr.arr[arr.length - i] = 0;
    }
}
void arrStringFree(char** arr) {
    int arrLen = getArrStringLen(arr);
    arrStringPop(arr,arrLen);
    free(arr);
}
// void arrStringPrint(dArrString &arr) {
//     for(int i = 0; i < arr.length; i++) {
//         printf("[Index:%d, String: %s]\n",i,arr.arr[i]);
//     }
    
// }