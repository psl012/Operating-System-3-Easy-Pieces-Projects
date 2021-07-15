#include <stdio.h>
#include <stdlib.h>

int main()
{
    int letterCount;
    char letter;

    FILE * fr;

    fr = fopen("Test_Test.txt", "r");

    while(1)
    {
        fread(&letterCount, 1, 4, fr);
        fread(&letter, 1, 1, fr);

        if(feof(fr))
        {
            break;
        }

        printf("%d", letterCount);
        printf("%c", letter);

    }
    fclose(fr);

    return 0;
}
