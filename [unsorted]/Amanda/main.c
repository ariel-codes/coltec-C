/**
 * Prompts user for as many as MAX values until EOF is reached, 
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount of hay
#define MAXSIZE 1024

int main(int argc, char* argv[]){
    int haysize;
    // ensure proper usage
    if(argc == 3){
        haysize = atoi(argv[2]);
    }
    else if (argc == 2){
        haysize = MAXSIZE;
    }
    else{
        printf("Usage: ./find needle [haystack_size]\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int i;
    int haystack[haysize];
    printf("Needle: %d\nHaystack size: %d\n", needle, haysize);
    for(i=0; i<haysize; i++){
        haystack[i] = rand() % haysize;
    }
    print_array(haystack, haysize);

    // sort the haystack
    sort(haystack, haysize);
    print_array(haystack, haysize);

    // try to find needle in haystack
    if (search(needle, haystack, haysize))
    {
        printf("Found needle in haystack!\n");
        return 0;
    }
    else
    {
        printf("Didn't find needle in haystack.\n");
        return 1;
    }
}