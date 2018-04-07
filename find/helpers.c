/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
if(n < 0)
{
    return false;
}
int left = 0;
int right = n;

while (n > 0)
{
    //int left = 0;
    int middle = (right/2) + (left/2);
    //int right = n-1

   // if (value == values[((n - 1) / 2)])
   if (value ==values[middle])
    {
        return true;
    }
    else if (value > values[middle])
    {
       // values= right side of array
        n = n/2; //length of right side of array
        left = middle + 1;
        //right = n - 1;
    }
    else if (value< values[middle])
    {
       // values = left side of array
        n = n/2; //length of left side array

        right = middle - 1;
    }
}

return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    return;
}
