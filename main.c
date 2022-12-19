#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include ".\programs\silnia\silnia.c"
//silnia()

//INCLUDE MENU
#ifdef _WIN32
    #include <conio.h>
    #include ".\menu\clearConsoleWin.c"
    // clearConsole()

    // arrow key is going like a clock: 
    // arrow up - 72, arrow rigt - 77, arrow down - 80, arrow left - 75
    #define ARROW_KEY {0,72,77,80,75} 
    #define ENTER_KEY 13
#elif __linux__
    #include ".\menu\getch.c"
    #include ".\menu\clearConsoleLinux.c"
    #define ARROW_KEY {1,65,67,66,68} 
    #define ENTER_KEY 10
#elif __unix__
    #include ".\menu\getch.c"
    #include ".\menu\clearConsoleLinux.c"
    #define ARROW_KEY {1,65,67,66,68} 
    #define ENTER_KEY 10
#endif


#include ".\menu\setColor.c"
// txtColor()
// bgColor()
#include ".\menu\getArrowDir.c"
//getArrowDir()
#include ".\menu\menu.c"
// typdef UIlist
// addMenuOption()
// getMenuSize()
// moveMenu()
// showMenu()
// menu


void start() {
    printf("hello");
}
void silnaApp() {
    printf("silnia");
}
void exitProgram() {
    printf("exit");
}

void showText(char *a){
    printf("%s", a);
}
int main()
{
    char menuText[][4096] = {"Start", "n!", "Exit"};
    addMenuOption(menuText[0], start);
    addMenuOption(menuText[1], silnaApp);
    addMenuOption(menuText[2], exitProgram);
    showMenu();

    int key = getch();
    // 27 it is Esc button
    // Animation loop
    int i = 0;
    while (key != 27){
        key = getch();

        int arrowKey = getArrowDir(key);
        if (arrowKey != 0) {
            int arrowDiraction = (arrowKey == 1 || arrowKey == 2) ? -1:1;
            moveMenu(arrowDiraction);
        }

        if (key == ENTER_KEY) {
            selectOption();
            break;
        }
        clearConsole();
        showMenu();
    }
    return 0;
}