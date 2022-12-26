#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../silnia/silnia.c"
long long potega(int a, int n) {
    if (n == 0) { return 1; }
    long long num = a;
    for (int i = 0; i < (n-1); i++){
        num *= a;
    }
    return num;
}

long long dwNewtona(int x, int y, int n) {
    long long expression = 0;
    for (int i = 0; i <= n; i++) {
        expression += (silniaLight(n) / (silniaLight(i) *  silniaLight(n - i))) * potega(x, n - i) * potega(y, 0 + i);
    }
    return expression;
}