char* decToAny(int n, int sys) {
    char pattern[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int nL = 4;
    char* num = (char*) malloc(nL * sizeof(char*));
    int i = 0;
    while (n > 0) {
        num[i] = pattern[n%sys];
        if (i >= nL-1) {
            nL *= 2;
            num = (char*)realloc(num, nL * sizeof(char*));
        }
        n /= sys;
        // printf("\n%d <- liczba, reszta -> %c , dlogosc %d, index %i",n, num[i], nL, i);
        i++;
    }
    for (int j = 0; j < (i/2); j++) {
        char a = num[j];
        num[j] = num[(i-1) - j];
        num[(i-1) - j] = a;
    }
    // for (int j = 0; j < (i/2); j++) {
    //     printf("%c", num[j]);
    // }
    num[i] = '\0';
    return num;
}