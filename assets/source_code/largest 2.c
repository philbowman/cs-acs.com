#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


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


    //your code here

}
