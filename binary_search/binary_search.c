#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"

int binary_search(int *arr, int n, int target){
    if(!arr || n == 0){
       return -1;
        
    }

    int mid;
    int low = 0;
    int high = n-1;

    while(low <= high){
        mid = low + (high-low) / 2;
        if(arr[mid]== target){
            return mid;
        }else if (arr[mid] > target){
            high = mid-1;
        }else if (arr[mid] < target){
            low = mid + 1;
        }
    }

    return -1;
}