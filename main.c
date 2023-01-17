#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "./programs/dArrayFun.c"
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
    printf("Proszę podać wyrażenie: ");
    char expr[4096];
    fgets(expr, sizeof(expr), stdin);
    dString inCalc;
    D_STRING(inCalc, expr);
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
    
    // D_STRING(inCalc, "14-2*3+7-3");
    // D_STRING(inCalc, "3*5-2+6");
    // D_STRING(inCalc, "(2+3)^3");
    // D_STRING(inCalc, "14-(2-4*5+33)*3");
    // D_STRING(inCalc, "5*(5+3)-5*(4+3)");
    // D_STRING(inCalc, "1*(5+(3*2)*(2+3))");
    // dStringConcat(&inCalc, "LOL");
    // printf("%s", inCalc.s);
    calculator(inCalc.s);

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