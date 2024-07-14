#include <iostream>
using namespace std;

void traversal(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

void selection_sort(int* arr, int size){
    int min_index, temp;
    for(int i = 0; i < size; i++){ //For number of passes
        min_index = i; // to store minimum value index so that even if new minimum number if found, it will store its new index value.
        for(int j = i+1; j < size; j++){ 
            if(arr[j] < arr[min_index]){ //To find minimum number index.
                min_index = j; 
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
int main(){
    int arr[] = {45,4,778,90,8};
    int size = sizeof(arr)/sizeof(int);
    selection_sort(arr, size);
    traversal(arr, size);
    return 0;
}