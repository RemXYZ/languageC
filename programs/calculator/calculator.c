// expr = expression
int calculator(char* expr) {
    // operator, waga
    char weight[][2][128] = {
        {"(,[\0", 0},
        {"+,-,)\0", 1},
        {"*,/,%\0",2},
        {"^\0", 3},
        {"log,sin,cos,tg,ctg\0", 4}
    };
}
