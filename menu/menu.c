#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Global Var
#define MENU_MAX_SIZE 32
#define MENU_TEXT_SIZE 4096


typedef struct 
{
    char texts[MENU_MAX_SIZE][MENU_TEXT_SIZE];
    void (*callbacs[MENU_MAX_SIZE])();
    int size;
    int head;
} UIlist;
UIlist menu = {{""}, {NULL}, 0, 0};
//How to put function into another function ?
//https://www.javatpoint.com/function-pointer-as-argument-in-c#:~:text=We%20cannot%20pass%20the%20function,holds%20the%20address%20of%20arguments.
UIlist addMenuOption(char *text, void (*callback)()){
    strcpy(menu.texts[menu.size], text);
    menu.callbacs[menu.size] = callback;
    menu.size++;
    return menu;
}
int getMenuSize(){
    return menu.size;
}
// if move is -1, it means go up, if move is 1 it means go down
void moveMenu(int move) {
    menu.head = menu.head + move;
    if (menu.head >= menu.size) {menu.head = 0;}
    if (menu.head < 0) {menu.head = menu.size - 1;}
    // printf("MOVE MENU Head:%d, size %d\n", menu.head, menu.size);
}
void selectOption() {
    menu.callbacs[menu.head]();
}


void showMenu() {
    for (int i = 0; i < getMenuSize(); i++) {
        //set color
        if (menu.head == i) {txtColor(fgBlack);bgColor(bgWhite);}
        menu.callbacs[i]();
        printf("\nsize %d, text: %s\n\n", getMenuSize(), menu.texts[i]);
        if (menu.head == i) {txtColor(resetColor);}
    }
}