#include <iostream>
using namespace std;

void traversal(int* arr, int size){
    for(int i = 0; i <size; i++){
        cout<<arr[i]<<" ";
    }
}

void merg(int* arr, int low, int mid, int high){  // This will merge all separate arrays
    int i = low;
    int j = mid+1;
    int k = low;
    int arr2[high+1]; // New array
    while(i <= mid && j <= high){ //Till one of i or j elements are empty and remaining elements will be directly inserted with remaining two while loop
        if(arr[i] < arr[j]){
            arr2[k] = arr[i];
            i++;
            k++; 
        }
        else{
            arr2[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid){  // To insert remaining elements when j element are filled
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){   // To insert remaining elements when i element are filled
        arr2[k] = arr[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++){  // To copy new arrays element in main array
        arr[i] = arr2[i];
    }
}

int merging_sort(int* arr, int low, int high){
    int mid = (low + high)/2;
    if(low < high){
        merging_sort(arr, low, mid);    // This will reduce left side array
        merging_sort(arr, mid+1, high); // This will reduce right side array
        merg(arr, low, mid, high);
    }
}
int main(){
    int arr[] = {67,45,3,67,89,9,47};
    int size = sizeof(arr)/sizeof(int);
    merging_sort(arr, 0, size - 1);
    traversal(arr, size);
    return 0;
}