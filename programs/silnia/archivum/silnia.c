#include <stdio.h>
//http://www.elektronik.lodz.pl/wbrzo/03/dod/printf.html

int silnia(int num) {
    if (num <= 0) {
        return 0;
    }
    else if(num == 1) {
        return 1;
    }
    int sum = 1;
    for (int i = 1; i <= num; i++) {
        sum *= i;
    }

    return sum;
}


int main()
{

    int hello[6] = {1,2,0};
    hello[5] = '\000';
    //tablica(hello, 6);

    printf("Wprowadz liczbe\n");
    int n;
    scanf("%d", &n);
    int sil = silnia(n);
    printf("%d\n", sil);

    return 0;

}