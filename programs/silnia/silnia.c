#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** addArray(int *A, int *B, int lA, int lB) {
    // main length
    int maxL = lA, minL = lB, dif = lA - lB;
    int *maxArr = A;
    int *minArr = B;
    if (dif < 0) {maxL = lB; minL = lA; dif *= -1; maxArr = B; minArr = A;}
    int *Aout = (int *) malloc(maxL * sizeof(int));
    int *outL = (int *) malloc(1 * sizeof(int));
    outL[0] = maxL;
    int overflow = 0;
    int num;
    
    // printf("%d,%d\n", maxL, minL);
    for (int maxI = maxL-1; maxI >= 0; maxI--) {
        int minI = maxI - dif;
        if (minI >= 0) {
            num = maxArr[maxI] + minArr[minI];

        }else {
            num = maxArr[maxI];
            // printf(" ");
            
        }
        if (overflow == 1) {
            num += overflow;
            overflow = 0;
        }
        if (num > 9) {num = num % 10; overflow = 1;}
        // printf("%d", num);
        Aout[maxI] = num;
    }
    if (overflow == 1) {
        Aout = (int *) realloc(Aout, (maxL + 1) * sizeof(int));
        outL[0] = maxL + 1;
        int c = Aout[0];
        for (int i = outL[0] - 2; i >= 0; i--) {
            Aout[i+1] = Aout[i];
        }
        if (outL[0] > 2) {}
        Aout[0] = 1;
    }
    // printf("\n%d\n\n", outL);
    // for (int i = 0; i < outL; i++) {
    //     printf("%d\n", Aout[i]); 
    // }
    int **outData = (int **) malloc(2 * sizeof(int));
    outData[0] = Aout;
    outData[1] = outL;
    return outData;
}


int** multiplyArray(int *A, int m, int lA) {
    if (m == 1) {
        int **outData = (int **) malloc(2 * sizeof(int));
        int *lA2 = (int *) malloc(1 * sizeof(int));
        lA2[0] = lA;
        outData[0] = A;
        outData[1] = lA2;
        return outData;
    }
    //new Array
    int* nA = (int *) malloc(lA * sizeof(int));
    // new length
    int *nL = (int *) malloc(1 * sizeof(int));
    nL[0] = lA;
    memcpy(nA, A, lA * sizeof(int));

    for (int i = 0; i < m-1; i++) {
        int **newA = addArray(nA, A, nL[0], lA);
        nA = newA[0];
        nL = newA[1];
        // printf("\n\n%d\n", nL[0]);
        // for (int i = 0; i < nL[0]; i++) {
        //     printf("%d", nA[i]);
        // }

    }

    // addArray(A, A, lA, lA);
    int **outData = (int **) malloc(2 * sizeof(int));
    outData[0] = nA;
    outData[1] = nL;
    return outData;
}


int silnia(int num) {
    if (num <= 0) {
        printf("0");
        printf("\n\nTa wartosc ma %d cyfre\n", 1);
        return 1;
    }
    if(num == 1) {
        printf("1");
        printf("\n\nTa wartosc ma %d cyfre\n", 1);
        return 1;
    }
    int *lA = (int *) malloc(1 * sizeof(int));
    lA[0] = 1;
    int *A = (int *) malloc(lA[0] * sizeof(int));
    A[0] = 2;

    for (int i = 3; i <= num; i++) {
        int **newA = multiplyArray(A, i, lA[0]);
        A = newA[0];
        lA = newA[1];
        // printf("\n\n%d HELLO %d\n", lA[0], i);
        // for (int i = 0; i < lA[0]; i++) {
        //     printf("%d", A[i]);
        // }

    }
    // Shows number
    printf("n! = ");
    for (int i = 0; i < lA[0]; i++) {
        printf("%d", A[i]);
    }
    if (lA[0] == 1) {
        printf("\n\nTa wartosc ma %d cyfre\n", lA[0]);
    }else if (lA[0] > 1 && lA[0] <= 4){
        printf("\n\nTa wartosc ma %d cyfry\n", lA[0]);
    }else{
        printf("\n\nTa wartosc ma %d cyfr\n", lA[0]);
    }
    free(lA);
    free(A);
    return 1;
}

long long silniaLight(int n) {
    long long num = 1;
    for (int i = 2; i <= n; i++) {
        num *= i;
    }
    return num;
}
