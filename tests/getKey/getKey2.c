#include <stdio.h>
#ifdef _WIN32
    #include <conio.h>
#elif __linux__
#include <termios.h>
#include <unistd.h>
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
#include <termios.h>
#include <unistd.h>
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


int main()
{
    int arrow_presed = 0;
    while (1) {
        char key = getch();
        printf("%d, %c\n", key,key);
        if (key == 9) {
            break;
        }
    }
    
    return 0;
}
