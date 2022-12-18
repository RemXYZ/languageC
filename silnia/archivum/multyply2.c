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
        Aout = realloc(Aout, (maxL + 1) * sizeof(int));
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


int multiply(int A, int m, int lA) {
    
    return 1;
}


int main()
{

// int* hi = hello();
// printf("%d", hi[1]);

int A[5] = {9,9,5,9,9};
int B[1] = {9};
int **newA = addArray(A, B, 5, 1);
int *myArr = newA[0];
int newL = newA[1][0];
printf("\n%d\n", newL);
for (int i = 0; i < newL; i++) {
    printf("%d\n", myArr[i]); 
}

}