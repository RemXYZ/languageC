#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
    #include <conio.h>
#elif __linux__
    #include ".\getch.c"
#elif __unix__
    #include ".\getch.c"
#endif

//Global Var
#define MENU_MAX_SIZE 32
#define MENU_TEXT_SIZE 4096


char MenuTextList[MENU_MAX_SIZE][MENU_TEXT_SIZE];
void (*MenuCallBackList[MENU_MAX_SIZE])();
int MenuSize = 0;


// void addMenuOption(char *text, int* callback){
//     strcpy(MenuTextList[MenuSize], text);
//     MenuCallBackList[MenuSize] = callback;
//     MenuSize++;

// }

int getMenuSize(){
    return MenuSize;
}

void lol(){
    printf("kek");
}

void showMenu() {
    char text[] = "Hello";
    // addMenuOption(text, lol);
    // if (MenuTextList > MENU_MAX_SIZE) MenuTextList = MENU_MAX_SIZE;
    for (int i = 0; i < MenuSize; i++) {
        printf("str %d = %s\n", i, MenuTextList[i]);
        printf("str %d = %d\n", i, MenuCallBackList[i]);
    }
}