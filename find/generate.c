/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // program expects one or two command line arguments, so if argc does not equal 2 or 3, prints usage and returns 1
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Converts the first command line argument, the number of random intergers, to an integer
    int n = atoi(argv[1]);

    // checks argc to see if there is a second command line argument that the pseudorandom-number generator will use as a seed
    if (argc == 3)
    {
        srand48((long) atoi(argv[2])); //if second command line arg exists, converts to int and passes to function srand48()
    }
    else
    {
        srand48((long) time(NULL)); //if it does not exist,
    }

    // generates the random number up to the amount of numbers the user entered as the first command line argument and prints.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
