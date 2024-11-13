#include <stdio.h>

void merge(int Arr[], int p, int q, int r);

void merge_sort(int Arr[], int p, int r);

void test_mergeSort();



void merge(int Arr[], int p, int q, int r){
    int length_left = q - p + 1;
    int length_right = r - q;

    int left_array[length_left];
    int right_array[length_right];

    for(int i = 0; i<length_left; i++){
        left_array[i] = Arr[p+i];
    }

    for(int j = 0; j<length_right; j++ ){
        right_array[j] = Arr[q+j+1];
    }
    int i = 0;
    int j = 0;
    int k = p;

    while(i < length_left && j < length_right){
        if(left_array[i] <= right_array[j]){
            Arr[k] = left_array[i];
            i++;
        }
        else{
            Arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < length_left){
        Arr[k] = left_array[i];
        i++;
        k++;
    }

    while(j < length_right){
        Arr[k] = right_array[j];
        j++;
        k++;
    }
}


void merge_sort(int Arr[], int p, int r){
    if(p>=r)
        return;
    int q = (p+r) / 2;
    merge_sort(Arr, p, q);
    merge_sort(Arr, q+1, r);
    merge(Arr, p, q, r);
}


void test_mergeSort(){
    int Arr[] = {6, 98, 43, 32, 21, 15, 18,100, 35, 54, 43, 64, 87, 43, 34, 32, 1, 5, 4, 3};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    merge_sort(Arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d, ", Arr[i]);
    }
    printf("\n");
}

int main(){

    test_mergeSort();
    return 0;
}






