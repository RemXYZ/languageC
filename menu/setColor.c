// back ground colours
char bgBlack[] = "\e[40m";
char bgRed[] = "\e[41m";
char bgGreen[] = "\e[42m";
char bgYellow[] = "\e[43m";
char bgBlue[] = "\e[44m";
char bgMagenta[] = "\e[45m";
char bgCyan[] = "\e[46m";
char bgWhite[] = "\e[47m";

//bright background colours

char bgbBlack[] = "\e[40;1m";
char bgbRed[] = "\e[41;1m";
char bgbGreen[] = "\e[42;1m";
char bgbYellow[] = "\e[43;1m";
char bgbBlue[] = "\e[44;1m";
char bgbMagenta[] = "\e[45;1m";
char bgbCyan[] = "\e[46;1m";
char bgbWhite[] = "\e[47;1m";

// foreground light colours

char fgBlack[] = "\e[30m";
char fgRed[] = "\e[31m";
char fgGreen[] = "\e[32m";
char fgYellow[] = "\e[33m";
char fgBlue[] = "\e[34m";
char fgMagenta[] = "\e[35m";
char fgCyan[] = "\e[36m";
char fgWhite[] = "\e[37m";

//foreground bright colors

char fgbBlack[] = "\e[30;1m";
char fgbRed[] = "\e[31;1m";
char fgbGreen[] = "\e[32;1m";
char fgbYellow[] = "\e[33;1m";
char fgbBlue[] = "\e[34;1m";
char fgbMagenta[] = "\e[35;1m";
char fgbCyan[] = "\e[36;1m";
char fgbWhite[] = "\e[37;1m";

//reset foreground and background to normal colours

char resetColor[] = "\e[0m";

void txtColor(char *a){
    printf("%s",a);
}
void bgColor(char *b){
    printf("%s",b);
}