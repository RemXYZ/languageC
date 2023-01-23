#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

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
    //Operators[][8][16]
    // splitExpr()
    // toRPN()
    // doArith()
    // doArithFun()
    // calculteRPN()
    // calculator()
#include "./programs/calkowanie/posVal.c"
// findVarPos()
// funSubstitution()
#include "./programs/liczeniePi/liczeniePi.c"
    // liczeniePi()
#include "./programs/calkowanie/calkowanie.c"
    // funSubstitution()
    // integral()


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
int calculatorApp(int mode){
    
    printf("Prosze podac wyrazenie:\n");
    char expr[4096];
    fgets(expr, sizeof(expr), stdin);
    clearConsole();

    // dString inCalc;
    // D_STRING(inCalc, expr);
    calculator(expr, mode);

    printf("\n");
    // free(inCalc.s);
    optionExitMsg();
    return 1;
}

// Nie wiem, czy istnieje lambda w C, zeby to wygladalo inaczej ?
int calculatorMode1() {calculatorApp(1);}
int calculatorMode2() {calculatorApp(2);}

int calculatorMenu() {
    printf("Prosze podac tryb wpisywana:\n");
    char menuText[][4096] = {
        "Zwykly zapis, np. (3+2)*2",
        "Zapis w ONP, np. 3 2 + 2 * (posze robic spacje miedzy liczbami)",
        "Wroc"
    };
    resetMenu();
    addMenuOption(menuText[0], calculatorMode1);
    addMenuOption(menuText[1], calculatorMode2);
    addMenuOption(menuText[2], mainMenu);
    clearConsole();
    showMenu();
}

// Liczenie PI
int PIApp() {
    liczeniePi();
    printf("\n");
    optionExitMsg();
    return 1;
}

int integralApp() {
    clearConsole();
    printf("~~~Calkowanie metoda prostokatow:~~~\n\n");

    printf("Program pozwala uzywac nastepujace funkcje matematyczne:\n\
FUNCTION - PRZYKLAD\n\
sqrt()-  sqrt(4+12);\nsin() - sin(6)\ncos() - cos(6);\ntg() - tg(6);\nlog() - log(10)\n\n");
    printf("Prosze podac funkcje:\n");
    char fun[4096];
    fgets(fun, sizeof(fun), stdin);

    double a, b;
    int n;
    printf("Prosze podac poczatek przedzialu calkowania:\n");
    scanf("%lf", &a);
    printf("Prosze podac koniec przedzialu calkowania:\n");
    scanf("%lf", &b);
    printf("Prosze podac liczbe prostokatow \n(Im wiecej liczba, tym precezyjniej bedzie odpowiedz):\n");
    scanf("%d", &n);

    // dString inInteg;
    // // D_STRING(inInteg, "1/(1+x^2)");
    // // D_STRING(inInteg, "x+x^5");
    // D_STRING(inInteg, "4^x");
    dArrString rpnArr = toRPN(fun);
    integral(&rpnArr, a, b, n);
    dArrStringFree(&rpnArr);

    printf("\n");
    optionExitMsg();
    return 1;
}

// MAIN MENIU OPTIONS
int mainMenu() {
    char menuText[][4096] = {
        "Kalkulator",
        "Calkowanie",
        "Silnia n!",
        "Dwumian Newtona ( n )\n\
                ( k )", 
        "System dziesietny -> system *",
        "Liczenie liczby PI",
        "Exit"
    };
    resetMenu();
    addMenuOption(menuText[0], calculatorMenu);
    addMenuOption(menuText[1], integralApp);
    addMenuOption(menuText[2], silnaApp);
    addMenuOption(menuText[3], dwNewtonaApp);
    addMenuOption(menuText[4], decToAnyApp);
    addMenuOption(menuText[5], PIApp);
    addMenuOption(menuText[6], exitProgram);
    clearConsole();
    showMenu();
    return 1;
}

int main()
{
    srand(time(0));
    // D_STRING(inCalc, "14-2*3+7-3");
    // D_STRING(inCalc, "3*5-2+6");
    // D_STRING(inCalc, "(2+3)^3");
    // D_STRING(inCalc, "14-(2-4*5+33)*3");
    // D_STRING(inCalc, "5*(5+3)-5*(4+3)");
    // dString inCalc;
    // D_STRING(inCalc, "3*(1+4)+4");
    // calculator(inCalc.s, 1);

    // dStringConcat(&inCalc, "LOL");
    // printf("%s", inCalc.s);
    // int xd[10] = {20,30,40,50};
    // dDouble lol;
    // D_DOUBLE(lol);
    // int i = 2;
    // dDoublePush(&lol, i);
    // dDoublePrint(&lol);

    // printf("XD: %d", (int)lol.arr[0]);


    // dInt varPos;
    // D_INT(varPos);
    // for (int i = 0; i < 10; i++) {
    //     dIntPush(&varPos, i);
    // }
    // dIntPrint(&varPos);
    // return 0;
    // dArrString lol;
    // D_ARR_STRING(;lol);
    // dArrStringPush(&lol, "Heh");
    // dArrStringPush(&lol, "lol");
    // dArrStringPush(&lol, "))");
    // dArrStringPush(&lol, ")");
    // dArrStringPush(&lol, ")");

    // dArrStringPop(&lol, 1);
    // dArrStringPrint(&lol);
    // return 0;

    // char expr[4096] = "sqrt(sqrt(16^2))";
    // calculator(expr, 1);
    
    // return 0;
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