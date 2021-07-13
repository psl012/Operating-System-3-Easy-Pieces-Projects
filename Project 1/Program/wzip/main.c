#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letterLine[2];
    char currentLetter = NULL;
    int letterCounter = 0;

    FILE * fr;
    FILE * fo;

    fr  = fopen("Test_Case.txt", "r");
    fo = fopen("Answer.txt", "w");


    while(fgets(letterLine, 2, fr) != NULL)
    {
        if(currentLetter == letterLine[0])
        {
            letterCounter++;
        }
        else if (currentLetter == NULL)
        {
            currentLetter = letterLine[0];
            letterCounter++;
        }
        else
        {
            printf("%d", letterCounter);
            printf("%c", currentLetter);
            fwrite(&letterCounter, 4, 1, fo);
            fwrite(&currentLetter, 1, 1, fo);
            currentLetter = letterLine[0];
            letterCounter = 1;
        }
    }


    currentLetter = letterLine[0];

    printf("\nHello world!\n");
    return 0;
}
