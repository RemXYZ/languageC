#include <stdio.h>
#include <stdlib.h>

void wypisz(int *arr, int length) {
    // tu zauważ, że gwizdka działa jak odsyłać, i to faktycznie tak działa, pokazujemy miejsce w pamięci, gdzie się znajduje ta tablica
    printf("Tu sie pojawi wszystkie elementy wpisane przez ciebie:\n");
    for (int i=0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int** get_arr() {
    int* myArr; // to będzie stworzoną tablicą
    int myLength = 4; // to będzie długością tej tablicy

    myArr = (int*) malloc(myLength * sizeof(int));
    for (int i=0; i < myLength; i++) {
        myArr[i] = i;
    }

    int** arrReturn = (int**) malloc(2 * sizeof(int)); // tutaj mamy 2 GWIAZDKI, bo tablica przyjmuje tablicę
    arrReturn[0] = myArr;
    *arrReturn[1] = myLength; //w tym miejscu robię jakby odsyłanie do zmiennej długości, więc * powinna być przez arrReturn[1]
    return arrReturn;
}


int main() {
    // Dynmiczna tablica ma jedyne zalety ( no trochę wad też ma )
    // Po pierwsze możesz wskazać ile elementów chcesz, żeby było w tablice
    int length;
    printf("Wpisz dlugosc tablicy\n");
    scanf("%d", &length); // To pobiera wartość z konsoli i zapisuję do zmiennej

    int* arr; // w ten sposób deklaruje się zmienna do tablicy dynamicznej, nie musisz się przyjmować dlaczego ma *

    arr = (int*) malloc(length * sizeof(int)); //o tej linijce przeczytaj lub obejrzyj w internecie

    printf("Wpisz elementy tablicy\n");
    for (int i=0; i < length; i++) {
        // tu wpisujesz wartości do tablicy
        scanf("%d", &arr[i]);
    }
    // fajna zeletą jest to, że możesz łatwo przekazywać tę tablicę do argumentu w funkcji
    wypisz(arr, length); 
    // Zawsze, jak skończysz prace z tablicą dynamiczną, musisz ją usunąć za pomocą free()
    free(arr);







    // i teraz popatrz na to !
    // Z łatością możesz uzyskać zwróconą tablicę i długość tej tablicy z funkcji! Co jest (chyba) nie możliwe ze zwykłymi tablicami
    int **newArray = get_arr();
    
    int myLength = newArray[1][0]; //tutaj wyciągam długość
    int* myArr = newArray[0]; // tutaj nowa tablica myArr przyjmuję link do tablicy z funkcji get_arr()

    printf("Dlugosc tablicy pobranej z funckji get_arr: %d\n",myLength);
    printf("Elementy tblicy: \n");
    for (int i=0; i < myLength; i++) {
        printf("%d ", myArr[i]);
    }
    free(myArr); // i znowu oczyszczamy tablicę z pamięci
    return 0;
}