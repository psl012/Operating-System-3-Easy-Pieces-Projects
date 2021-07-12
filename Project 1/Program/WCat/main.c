#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    char str[100];


    fp = fopen("Test_Case_01.txt", "r");

    if(fp == NULL)
    {
        printf("cannot open file \n");
        return 1;
    }

    for(int i = 0; i < 1000; i++)
    {
        if(fgets(str, 100, fp) != NULL)
        {
            printf("%s", str);
        }
        else
        {
            break;
        }
    }

    fclose(fp);
    return 0;
}
