#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letterLine[2];
    char currentLetter = NULL;
    char lastLetter;
    int letterCounter = 0;
    int lastLetterCounter = 0;

    int iteCounter = 0;
    //_bool differentLastLetter = false;

    FILE * fr;
    FILE * fo;


    fr  = fopen("Test_Case_04.txt", "r");
    fo = fopen("Test_Case_04_Answer.txt", "w");


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
         //   printf("%d", letterCounter);
        //    printf("%c", currentLetter);

            fwrite(&letterCounter, 4, 1, fo);
            fwrite(&currentLetter, 1, 1, fo);

            lastLetter = currentLetter;
            lastLetterCounter = letterCounter;

            currentLetter = letterLine[0];
            letterCounter = 1;
        }
    }

    currentLetter = letterLine[0];
    printf("\nHello world!\n");

    return 0;
}
