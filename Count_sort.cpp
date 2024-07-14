#include <iostream>
#include <climits> // To use INT_MAX
using namespace std;

void traversal(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int maxmimum(int arr[], int size){
    int max = INT_MIN; // INT_MIN is very small number. it is in negative billion number. We are assign this negative number to max
                       // so that during comparison, if any negaive small number exist, it cant be smaller than INT_MIN.
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int* arr, int size){
    int max = maxmimum(arr, size);
    int* count_arr = new int[max+1]; // New array of size max+1
    for(int i = 0; i < (max+1); i++){  // To initialize all elements of count arr to 0
        count_arr[i] = 0;
    }
    for(int i = 0; i < size; i++){     // To add 1 to index of number
        count_arr[arr[i]] = count_arr[arr[i]] + 1;
    } 
    int i = 0;
    int j = 0;
    while(j < max+1){
        if(count_arr[j] > 0){
            arr[i] = j;
            count_arr[j]--; // To reduce 1 to 0 after inserting
            i++;
        }
        else{
        j++;
        }
    }
    delete[] count_arr;
}
int main(){
    int arr[] = {56,34,23,12,4,7,90,8,8,89};
    int size = sizeof(arr)/sizeof(int);
    count_sort(arr, size);
    traversal(arr, size);
    return 0;
}