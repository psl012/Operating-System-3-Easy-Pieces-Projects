#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letterLine[2];
    char currentLetter = NULL;
    char lastLetter;
    int letterCounter = 0;
    int lastLetterCounter = 0;

    int itExitedDifferent = 1;
    int iteCounter = 0;

    FILE * fr;
    FILE * fo;


    fr  = fopen("Test_Case_01.txt", "r");
    fo = fopen("Test_Case_01_Answer.txt", "w");


    while(!feof(fr))
    {
        fgets(letterLine, 2, fr);
        if(currentLetter == letterLine[0])
        {
            letterCounter++;

            lastLetterCounter = letterCounter;
            lastLetter = currentLetter;
            itExitedDifferent = 0;
        }
        else if (currentLetter == NULL)
        {
            currentLetter = letterLine[0];
            letterCounter++;
        }
        else
        {
            itExitedDifferent = 1;

            fwrite(&letterCounter, 4, 1, fo);
            fwrite(&currentLetter, 1, 1, fo);

            lastLetter = currentLetter;
            lastLetterCounter = letterCounter;

            currentLetter = letterLine[0];
            letterCounter = 1;
        }
    }

    if(itExitedDifferent == 0)
    {
        lastLetterCounter--;
     //   printf("%d", lastLetterCounter);
    //    printf("%c", lastLetter);

        fwrite(&lastLetterCounter, 4, 1, fo);
        fwrite(&lastLetter, 1, 1, fo);
    }

    currentLetter = letterLine[0];
    printf("\nHello world!\n");

    return 0;
}
