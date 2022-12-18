#include <stdio.h>
#include <stdlib.h>


void tablica(int n) {
    int *A;
    A = (int *)malloc(n * sizeof(int));
    A[0] = 2;
    A[1] = 3;
    for (int i = 0; i < n; i++){
        printf("%d\n", A[i]);
    }
}


int main()
{

tablica(3);



return 0;

//EXEMPLE OF PROGRAM

int size;
scanf("%d", &size);



int *A;
A = (int *)calloc(size, sizeof(int));


printf("Print val\n");
for (int i = 0; i < 1; i++){
    printf("Heello");
    scanf("%d", &A[i]);
}

printf("The val in array is\n");

for (int i = 0; i < size; i++){
    printf("%d\n", A[i]);
}

free(A);

return 0;

}