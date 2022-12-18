#include <stdio.h>
#include ".\silnia\silnia_prog.c"
#include ".\menu\menu.c"


int main()
{

    return 0;
    printf("Podaj n, zeby obliczyc silnie z n\n");
    int n;
    scanf("%d", &n);
    printf("%d!=\n", n);

    silnia(n);
    return 0;
}