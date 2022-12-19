#include <stdio.h>
#include ".\programs\silnia\silnia_prog.c"
#include ".\menu\menu.c"

#include <stdlib.h>
#include <string.h>


typedef struct
{
    // void (*MenuCallBackList[5])();
    char text[100];
    int length;
} Hello;


void lol2(){
    printf("kek");
}
void lol3(){
    printf("kek2");
}

Hello pushsh(Hello obj) {
    printf("%s, %d rrr\n", obj.text, obj.length);
    strcpy(obj.text, "efe");
    obj.length = 5;
    return obj;
}


int main()
{
    // Hello lols = {{lol2, lol3}};
    // lols.MenuCallBackList[0]();
    // lols.MenuCallBackList[1]();
    // printf("%d", hih.length);
    Hello hih = {"wwww",2};
    hih = pushsh(hih);
    printf("%s, %d \n\n", hih.text, hih.length);
    // pushh(*lol2);
    // MenuCallBackList[0] = *lol2;
    // MenuCallBackList[0]();
    // showMenu();
    return 0;
}