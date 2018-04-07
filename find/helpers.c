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
int right = n-1;

while (n > 0)
{

    //int middle = (right/2) + (left/2);
    int middle = (right+left)/2;

   if (value == values[middle])
    {
        return true;
    }
    else if (value > values[middle])
    {
       // values= right side of array
        n = n/2; //length of right side of array
        left = middle + 1;
        //right = n;

        //right = n - 1;
    }
    else if (value< values[middle])
    {
       // values = left side of array
        n = n/2; //length of left side array

        right = middle - 1;
        //if (right<0){
          //  right = 0;
        //}
    }
}

return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
int lowest;
int index;
for(int i = 0; i<n; i++)
{
    for (int j = i+1; j<n; j++)
    {
        index = i;
        lowest = values[i];
        //lowest = values[j];
        if (values[j]<lowest)
        {
            lowest = values[j];
            index = j;
        }
        if (lowest<values[i])
        {
            values[index] = values[i];
            values[i] = lowest;
           // values[index] = values[i];
        }
    }
    //index = 0;
    //lowest
}
return;
}
