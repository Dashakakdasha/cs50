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
    if (value > 0)
    {
        int end = n - 1, start = 0;
        while (n > 0)
        {
            int mid = (start + end) / 2;

            if (values[mid] == value)
            {
                return true;
            }
            else if (values[mid] < value)
            {
                start = mid + 1;
            }
            else if (values[mid] > value)
            {
                end = mid - 1;
            }
            n = end - start + 1;
        }
        return false;
    }
    else
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Bubble sort
    int counter = 1;
    while (counter > 0)
    {
        counter = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                counter++;
            }
        }
    }
    return;
}
