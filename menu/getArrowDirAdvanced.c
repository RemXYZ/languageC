//INCLUDE MENU
#ifdef _WIN32
    // arrow key is going like a clock: 
    // arrow up - 72, arrow rigt - 77, arrow down - 80, arrow left - 75
    #define ARROW_KEY {0,224,72,77,80,75}
#elif __linux__
    #define ARROW_KEY {1,91,65,67,66,68} 
#else
    #define ARROW_KEY {1,91,65,67,66,68} 
#endif

int IsArrowPressed = 0;
int getArrowDir(int key) {
    int arrowkey[] = ARROW_KEY;
    if ((key == arrowkey[0]) || key == arrowkey[1]) IsArrowPressed = 1;
    if (IsArrowPressed == 0) return -1;
    
    for (int i = 2; i < sizeof(arrowkey)/sizeof(*arrowkey); i++) {
        if (arrowkey[i] == key) {
            IsArrowPressed = 0;
            return i-1;
        }
    }
    return -1;
}