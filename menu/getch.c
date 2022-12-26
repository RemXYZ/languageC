// SOURCE from here
// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
// and
// https://stackoverflow.com/questions/38191858/implicit-conversion-warning-with-own-getch-function
// https://gist.github.com/truthadjustr/43472242e5beb20d52c8a8892ee943c6
#include <termios.h>
#include <unistd.h>
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( 0u | ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

// END OF SOURCE