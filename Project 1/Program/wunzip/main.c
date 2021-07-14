#include <stdio.h>
#include <stdlib.h>

int main()
{
    int letterCount;
    char letter;

    FILE * fr;

    fr = fopen("Last_Test_Case.txt", "r");

    while(1)
    {
        fread(&letterCount, 1, 4, fr);
        fread(&letter, 1, 1, fr);

        if(feof(fr))
        {
            break;
        }

       // for(int i = 0; i < letterCount; i++)
        {
            printf("%d", letterCount);
            printf("%c", letter);
        }
    }
    return 0;
}
