#include <stdio.h>
#include <stdlib.h>

int main()
{
    // wgrep

    // a;ways passed a search term; but number of files can be zero or more
    // go through each line of the file and see if the search term is in it: if yes print the line
    // matching is case sensitive
    // Lines are arbitrary long: not recommended to set a limit (you can work this one by recycling memory) hint: use getline
    // If no command line-argument is passed:  print "wgrep: searchterm [file ...]" (followed by a newline) and exit with status 1
    // If wgrep encounters a file that it cannot open, it should print "wgrep: cannot open file" (followed by a newline) and exit with status 1.
    // if we have a search term but no file given then this will read from standard input (the scanf thingy)
    // If empty string is passed then either we automatically matched all the lines or we don't (all or nothing)

    printf("Hello world!\n");
    return 0;
}
