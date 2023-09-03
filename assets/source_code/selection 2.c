#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void printArray(int arr[], int size);
void swap(int *xp, int *yp);
void selection_sort(int arr[], int n);

int main(int argc, string argv[])
{
    if (argc< 2)
    {
        printf("Usage: ./largest.c [integer 1], [integer 2] ...");
        return 1;
    }

    int arr[argc-1]; //array to be sorted
    int n = argc-1; //length of array

    //populate array to be sorted from argv[]
    for (int i = 1; i < argc; i++)
    {
        arr[i-1] = atoi(argv[i]);
    }


    selection_sort(arr, n);

}

void selection_sort(int arr[], int n)
{

    //WRITE YOUR CODE HERE

    printArray(arr, n);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

// usage example: swap(&arr[1], &arr[2])
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}