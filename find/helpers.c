// PRC-MATT -  nice comments! Our search function is pretty much the same implentation, and you have great variable names and
// the comments make it easy to follow along. Same for your sort function, which was different than what i did so it is cool
// to see it done a different way.

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
    if (n < 0) // if there are no values in array, returns false
    {
        return false;
    }

    int left = 0; //keeps track of left side index of array, starts at index 0
    int right = n - 1; //keeps track of right side index of array, starts at end (n-1)

    while (n > 0) //while there are still numbers to check
    {
        int middle = (right + left) / 2; //finds the middle index of array

        if (value == values[middle]) //if the value we are trying to find equals value of int at middle index of array, return true
        {
            return true;
        }
        else if (value > values[middle]) //if value is greater, we need to search right side of array
        {
            n = n / 2; //updates length of array we are looking at (just the right side)
            left = middle + 1; //updates the left side of the array, we already checked middle so we set to middle + 1
        }
        else if (value < values[middle]) // if value is less than, we need to search left side of array
        {
            n = n / 2; //updates length of array we are looking at (just left side)
            right = middle - 1; //updates right side of array
        }
    }
    return false; //if value is not in values array, return false
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) //sorts values array smallest to largest
{
    int lowest; //keeps track of lowest number
    int index; // keeps track of index we are working on
    for (int i = 0; i < n; i++) // iterates through array starting at index 0
    {
        for (int j = i + 1; j < n; j++) // finds the lowest number in rest of array to place in index we are working on
        {
            index = i;
            lowest = values[i];
            if (values[j] < lowest) //finds lowest value in rest of array
            {
                lowest = values[j];
                index = j;
            }
            if (lowest < values[i]) //if lowest value found is less than value in index, switches these two values
            {
                values[index] = values[i];
                values[i] = lowest;
            }
        }
    }
    return;
}
