#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//INCLUDE MENU
#ifdef _WIN32
    #include <conio.h>
    #include ".\programs\silnia\silnia.c"
    // addArray()
    // multiplyArray()
    // silnia()

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





int start() {
    printf("hello");
    return 1;
}
int silnaApp() {
    clearConsole();
    printf("Prosze podac liczbe, zeby obliczyc silnie n!\nn = ");
    int n;
    scanf("%d", &n);
    silnia(n);
    printf("Nacisnij dowolna klawisze, zeby wrocic do menu...");
    getch();
    return 1;
}
int exitProgram() {
    printf("Exit...");
    return 0;
}
//Declare mainMenu
int mainMenu();

// int silniaMenu() {
//     char menuText[][4096] = {"Silnia n! dodatnia","Silnia 0","Cofnij", "Exit"};
//     resetMenu();
//     addMenuOption(menuText[0], silnaApp);
//     addMenuOption(menuText[1], start);
//     addMenuOption(menuText[2], mainMenu);
//     addMenuOption(menuText[3], exitProgram);
//     clearConsole();
//     showMenu();
//     return 1;
// }

int mainMenu() {
    char menuText[][4096] = {"Silnia n!", "Exit"};
    resetMenu();
    addMenuOption(menuText[0], silnaApp);
    addMenuOption(menuText[1], exitProgram);
    clearConsole();
    showMenu();
    return 1;
}

int main()
{
    mainMenu();

    int key;
    // 27 it is Esc button
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