#include <stdio.h>
#include <stdlib.h>

int main()
{
    // wgrep
    char currentLetter;
    char * searchTerm = "ssd";

    FILE * fr;

    fr = fopen("Test_Case_01.txt", "r");



    int checkPoint = 0;
    int counter = 0;
    int newLine = 0;
    int searchTermLength = 0;
    int searchTermCounter = 0;
    int isTermFound = 0;


    while(searchTerm[searchTermLength] != NULL)
    {
        searchTermLength++;
    }

    printf("%d", searchTermLength);
    printf("\n");

    while(fread(&currentLetter, 1, 1, fr))
    {
        // If newLine has just been detected previously thus we are now on the next line
        if(newLine == 1)
        {
            checkPoint = counter;
            newLine = 0;
        }

        // term has not been found
        if(isTermFound == 0)
        {
            // if letter matched our searched term
            if(currentLetter == searchTerm[searchTermCounter])
            {
                searchTermCounter++;
            }

            // letter did not match so we reset the counter
            else
            {
                searchTermCounter = 0;
            }

            // we have successfully found the sequence of letters that comprises the search term
            if(searchTermCounter == searchTermLength)
            {
                // Reset back our fp to the beginning of our current line
                fseek(fr, checkPoint, SEEK_SET);
                counter = checkPoint;
                // Iterate again but Print the Line (char per char) we will stop if we reach '\n'
                while(currentLetter != '\n')
                {
                    fread(&currentLetter, 1, 1, fr);
                    printf("%c", currentLetter);
                    counter++;
                }

                searchTermCounter = 0;
                counter--;
            }
        }

        if(currentLetter == '\n')
        {
            newLine = 1;
        }

        // use ftell to update our counter
        counter++;
    }
    // go through each line of the file and see if the search term is in it: if yes print the line
    // matching is case sensitive
    // Lines are arbitrary long: not recommended to set a limit (you can work this one by recycling memory) hint: use getline

    // If no command line-argument is passed:  print "wgrep: searchterm [file ...]" (followed by a newline) and exit with status 1
    // If wgrep encounters a file that it cannot open, it should print "wgrep: cannot open file" (followed by a newline) and exit with status 1.
    // if we have a search term but no file given then this will read from standard input (the scanf thingy)
    // If empty string is passed then either we automatically matched all the lines or we don't (all or nothing)

    fclose(fr);

    printf("\nHello world!\n");
    return 0;
}
