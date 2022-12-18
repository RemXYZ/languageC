#include <stdio.h>
#ifdef _WIN32
    #include <conio.h>
#elif __linux__
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#elif __unix__
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#else
    printf("Unidentified OS\n");
#endif
 
// back ground colours
#define bgBlack "\e[40m"
#define bgRed "\e[41m"
#define bgGreen "\e[42m"
#define bgYellow "\e[43m"
#define bgBlue "\e[44m"
#define bgMagenta "\e[45m"
#define bgCyan "\e[46m"
#define bgWhite "\e[47m"

//bright background colours

#define bgbBlack "\e[40;1m"
#define bgbRed "\e[41;1m"
#define bgbGreen "\e[42;1m"
#define bgbYellow "\e[43;1m"
#define bgbBlue "\e[44;1m"
#define bgbMagenta "\e[45;1m"
#define bgbCyan "\e[46;1m"
#define bgbWhite "\e[47;1m"

// foreground light colours

#define fgBlack "\e[30m"
#define fgRed "\e[31m"
#define fgGreen "\e[32m"
#define fgYellow "\e[33m"
#define fgBlue "\e[34m"
#define fgMagenta "\e[35m"
#define fgCyan "\e[36m"
#define fgWhite "\e[37m"

//foreground bright colors

#define fgbBlack "\e[30;1m"
#define fgbRed "\e[31;1m"
#define fgbGreen "\e[32;1m"
#define fgbYellow "\e[33;1m"
#define fgbBlue "\e[34;1m"
#define fgbMagenta "\e[35;1m"
#define fgbCyan "\e[36;1m"
#define fgbWhite "\e[37;1m"

//reset foreground and background to normal colours

#define Reset "\e[0m"

void txtColor(char a[]){

printf("%s",a);
}
void bgColor(char b[]){

printf("%s",b);
}

int main()
{
    int arrow_presed = 0;
    while (1) {
        char key = getch();
        txtColor(fgBlue);
        printf("%d, %c\n", key,key);
        txtColor(Reset);
        if (arrow_presed) {
            printf("Arrow has presed %d, %c\n", key,key);
            arrow_presed = 0;
        }
        if (key == 0) {
            arrow_presed = 1;
        }
        if (key == 9) {
            break;
        }
    }
    
    return 0;
}
