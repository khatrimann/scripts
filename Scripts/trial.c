#include <stdio.h>
int main()
{
    int integer, pos, neg;
    int poscounter, negcounter;
    integer = 0;
    pos = 0;
    neg = 0;
    poscounter = 0;
    negcounter = 0;

    do {
        printf("Please enter an integer:");

        scanf("%d", &integer);

        if (integer > 0) {
            pos += integer;
            poscounter++;
        }
        else if(integer < 0)    // Added else if for the logic as it was considering 0 as negative
        {
            neg += integer;
            negcounter++;
        }

    } while (integer != 0);
    printf("posc = %d\n", poscounter);      // Printed for confirmation
    printf("negc = %d\n", negcounter);      // Printed for confirmation
    
    /* Added these two ifs so that it can check any of the counters is not zero and it will not give (core dumped) */

    if(poscounter)
        printf("Positive average: = %d\n", pos / poscounter);
    if(negcounter)
        printf("Negative average: = %d\n", neg / negcounter);

        return 0;       // Adding this is a good practice
}