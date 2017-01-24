/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include "helpers.h"
#include <unistd.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n){
    int i;
    for(i=0; i<n; i++){
        if(values[i]==value)
            return true;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n){
    int i, new, swap;
    do{
        printf("Outer Loop\n");
        new = 0;
        for(i=1; i<n; i++){
            printf("\tInner Loop\n");
            if(values[i-1] > values[i]){
                swap = values[i];
                values[i] = values[i-1];
                values[i-1] = swap;
                new = i;
            }                
        }
        printf("\t\tPlaced %d\n", new);
        n = new;
    } while (n != 0);
}

/**
 * Prints an array in a pretty way
 */
void print_array(int array[], int size){
    printf("[%d", array[0]);
    int i;
    for(i=1; i<10; i++){
        printf(", ");
        printf("%d", array[i]);
    }
    printf("]\n");
}

