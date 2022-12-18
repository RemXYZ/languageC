#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* addArray(int *A, int *B, int n, int n2) {
    int *Aout = (int *) calloc(n,sizeof(int));


}

int* multiply(int *A, int n, int m) {

    int *Aout = (int *) calloc(n,sizeof(int));
    memcpy(Aout, A, n+2 * sizeof(int));
    int transfer = 0;



    for (int i = 0; i < m; i++) {
        for (int j = (n-1); j > 0; j--) {
            printf("%d", A[j]);
            printf("%d", Aout[j]);
            printf("\n");
        }
    }

    return Aout;
    free(Aout);
}


int main()
{

int n = 6;
int m = 2;
int *A = (int *) calloc(n,sizeof(int));
A[0] = 0;
A[1] = 4;
A[2] = 2;
A[3] = 3;
A[4] = 9;
A[5] = 9;

int *liczba = multiply(A, n, m);
printf("\n");
printf("\n");

int *Aout = (int *) calloc(n,sizeof(int));
memcpy(Aout, A, n+3 * sizeof(int));
for (int j = (n+3+4); j > 0; j--) {
    printf("%d\n", Aout[j]);

}
printf("end\n");
printf("\n");
free(A);

return 0;


}