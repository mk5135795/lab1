#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n;
    if(argc > 1)
    {
        n = atoi(argv[1]);
        if(argc > 2)
            srand(atoi(argv[2]));
        drawCharSquare(charSquare(n), n);
    }
    return 0;
}

char **charSquare(int n)
{
	char **square = new char*[n];
	for(int i(0); i < n * n; i++)
    {
        if(i < n)
            square[i] = new char[n];                    //nie wiedzialem czy "wypelnianie" jest polaczone z "tworzeniem" i czy moge uzyc osobnej petli for(;;) do stworzenia 2 wymiaru tablicy
        square[(i / n) % n][i % n] = rand() % 26 + 97;  // - (32 * rand() % 2); dla generatora wielkich i malych liter
    }
    return square;
}

void drawCharSquare(char **square, int n)
{
	for(int i(0); i < n * n; i++)
        printf("%c%c",
               (i % n == 0) ? '\n' : ' ' ,
               square[(i / n) % n][i % n]);
    return;
}
