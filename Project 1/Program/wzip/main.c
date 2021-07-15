#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letterLine[2];
    char currentLetter;
    char lastLetter;
    int letterCounter = 0;
    int lastLetterCounter = 0;

    int itExitedDifferent = 1;
    int firstRun = 1;

    FILE * fr;
    FILE * fo;


    fr  = fopen("Test_Case_06.txt", "r");
    fo = fopen("Test_Case_06_Answer.txt", "w");


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
        else if (firstRun == 1)
        {
            firstRun = 0;
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

        fwrite(&lastLetterCounter, 4, 1, fo);
        fwrite(&lastLetter, 1, 1, fo);
    }

    currentLetter = letterLine[0];
    printf("\nHello world!\n");

    fclose(fr);
    fclose(fo);

    return 0;
}
