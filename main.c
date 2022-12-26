#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./programs/dArray.c"
    // D_ARRAY()
#include "./programs/silnia/silnia.c"
    // addArray()
    // multiplyArray()
    // silnia()
    // silniaLight()
#include "./programs/dwumianNewtona/dwNewtona.c"
    // dwNewtona()
#include "./programs/decToAny/decToAny.c"
    // decToAny()
#include "./programs/calculator/calculator.c"
    // decToAny()


// INCLUDE MENU
// Cross Platform
#ifdef _WIN32
    #include <conio.h>

    #include ".\menu\clearConsoleWin.c"
    // clearConsole()
    #include ".\menu\setColor.c"
    // txtColor()
    // bgColor()
    #include ".\menu\getArrowDir.c"
    // getArrowDir()
    // ARROW_KEY
    #include ".\menu\menu.c"
    // typdef UIlist
    // addMenuOption()
    // getMenuSize()
    // moveMenu()
    // showMenu()
    // menu

    #define ENTER_KEY 13
//#elif __linux__
#else
    #include "./menu/getch.c"
    #include "./menu/clearConsoleLinux.c"
    // clearConsole()
    #include "./menu/setColor.c"
    // txtColor()
    // bgColor()
    #include "./menu/getArrowDir.c"
    // getArrowDir()
    // ARROW_KEY
    // IsArrowPressed
    #include "./menu/menu.c"
    // typdef UIlist
    // addMenuOption()
    // getMenuSize()
    // moveMenu()
    // showMenu()
    // menu
    #define ENTER_KEY 10
#endif

void optionExitMsg() {
    printf("Nacisnij Enter, zeby wrocic do menu...");
    getch(); // Dziala dla windows
    getchar(); // Dziala dla Linux, nie dziala dla windows
}

// MENU OPTION FUNCTIONS
// Declare mainMenu
int mainMenu();
int exitProgram() {
    printf("Exit...\n");
    return 0;
}
// Liczy dowolna silnie
int silnaApp() {
    clearConsole();
    printf("Prosze podac liczbe, zeby obliczyc silnie n!\nn = ");
    int n;
    scanf("%d", &n);
    silnia(n);

    optionExitMsg();
    return 1;
}
// Liczy dwumian Newtona
int dwNewtonaApp() {
    clearConsole();
    printf("\
(x+y)^n = ( n )           ( n )                     ( n )\n\
          ( 0 )*x^n*y^0 + ( 1 )*x^(n-1)*y^1 + ... + ( n )*x^0*y^n \
");
    printf("\nPodaj x:");
    int x,y,n;
    scanf("%d", &x);
    printf("\nPodaj y:");
    scanf("%d", &y);
    printf("\nPodaj n:");
    scanf("%d", &n);
    long long num = dwNewtona(x,y,n);
    printf("Dwumian Newtona wynosi: %lli\n", num);

    optionExitMsg();
    return 1;
}
// Funkcja odpalajca konwertacje z systemu dziesietnego do dowolnego
int decToAnyApp() {
    printf("Konwertacja z systemu dziezetnego na dowolny:\nPodaj liczbe w systemie dziesietnym: ");
    int n, sys;
    scanf("%d", &n);
    printf("\nPodaj system, do ktorego nalezy zamienic te liczbe:");
    scanf("%d", &sys);
    char* num = decToAny(n, sys);
    int i = 0;
    printf("Liczba w systemie %d wynosi:\n", sys);
    while (num[i] != '\0'){
        printf("%c", num[i]);
        i++;
    }
    printf("\n");
    free(num);

    optionExitMsg();
    return 1;
}
// Kalkulator zadanie 14 z zestawu 4
int calculatorApp(){

    return 1;
}

// MAIN MENIU OPTIONS
int mainMenu() {
    char menuText[][4096] = {
        "Silnia n!",
        "Dwumian Newtona ( n )\n\
                ( k )", 
        "System dziesietny -> system *",
        "Kalkulator",
        "Exit"
    };
    resetMenu();
    addMenuOption(menuText[0], silnaApp);
    addMenuOption(menuText[1], dwNewtonaApp);
    addMenuOption(menuText[2], decToAnyApp);
    addMenuOption(menuText[3], calculatorApp);
    addMenuOption(menuText[4], exitProgram);
    clearConsole();
    showMenu();
    return 1;
}

int main()
{
    // char wiersz[ 18 ];
    // fgets( wiersz, 18, stdin );
    // printf( "Wczytany tekst: %s\n", wiersz );
    // return 0;
    // char* num = decToAny(32, 2);
    // int i = 0;
    // printf("gggg");
    // while (num[i] != '\0'){
    //     printf("%c", num[i]);
    //     i++;
    // }
    // printf("\n");




    /////////// dARRAY TEST//////////
    
    // dCharArray cArr = {(char*) malloc(4 * sizeof(char*)), 4, pu, pu, po};
    // cArr.a[0] = 'A';
    // cArr.a[1] = 'L';
    // cArr.a[2] = 'o';
    // cArr.a[3] = '\0';
    // strcpy(cArr.a, "Lo");

    // printf("\n Array: %s", cArr.a);
    // printf("\nLength: %d ", cArr.length);
    // cArr.push(cArr);
    // cArr.pop(cArr);

    D_ARR_STRING(dArr, "HelloFIRSTSET");
    // printf("\n\n%s and length: %d",dArr.a, dArr.length);
    printf("\n");
    // dArr.set(dArr, "Ther");
    dArr.pop(dArr, 2);
    printf("Hello?%s, l: %i\n", dArr.a, dArr.length);

    dArr.cat(dArr, " CONCATENETED!!!");
    dArr.pop(dArr, 5);
    printf("\n\n\nIT IS 2 TIME Length: %d, size: %d, Tekst: %s\n\n", dArr.length, sizeof(dArr.a)/sizeof(dArr.a[0]), dArr.a);
    // D_ARR_STRING(dArr2, "Hello2");
    // printf("%s",D_ARR_STRING_dArr2_BUFFER);

    // const char* lol = (char*) malloc(0 * sizeof(char*));
    // lol = "Hello";
    // printf("%s\n", lol);
    // lol = "Loool";
    // printf("%s and %d", lol, strlen(lol));

    return 0;
    mainMenu();
    // printf("%d",silniaLight(5));
    // return 0;
    int key;
    // 27 it is Esc button
    // 9 it is Tab button in Windows and Linux
    // Animation loop
    while (key != 9){
        // waiting for press button
        key = getch();
        // Whe user press enter, it shows option function, and after clear console
        if (key == ENTER_KEY) {
            int opitonOut = selectOption();
            // printf("\n ggg%d", opitonOut);
            if (opitonOut == 0) {break;}
        }
        clearConsole();
        // printf("%d", key);

        int arrowKey = getArrowDir(key);
        if (arrowKey != -1) {
            int arrowDiraction = (arrowKey == 0 || arrowKey == 1) ? -1:1;
            moveMenu(arrowDiraction);
        } 
        // else {
        //     continue;
        // }

        
        showMenu();
        // printf("My key:%i, arr:%d, index %i\n", key, arrowKey, i);
        
    }
    return 0;
}