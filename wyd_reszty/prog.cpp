#include <stdio.h>

using namespace std;

int main()
{
    int iloscMonet = 3;
    int monety[iloscMonet] = { 1, 2, 5};
    int reszta = 0;

    printf("Jaka reszte chcesz wydac?");
    scanf("%d", &reszta);

    int licznik = 0;

    while (reszta > 0)
    {
        int nominal = 0;
        for (int i = 0; i < iloscMonet; ++i)
        {
            if ((monety[i] <= reszta) && (monety[i] > nominal))
            {
                nominal = monety[i];
            }
        }
        reszta = reszta - nominal;
        licznik++;
    }

    printf("Reszte mozna wydac %d monetami ", licznik);

    return 0;
}