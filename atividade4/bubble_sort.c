#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void suap(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void bubble_sort(int arr[], int n)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - j; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                suap(&arr[j], &arr[j + 1]);
            }
        }
    }
}