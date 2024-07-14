#include <iostream>
using namespace std;

void traversal(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int* arr, int low, int high){
    int pivot = arr[low];
    int i = low + 1;     
    int j = high;
    int temp;
    do{
        while(arr[i] <= pivot){        
            i++;
        }
        while(arr[j] >= pivot){
            j--;
        }
        if(i < j){  //Swapping when i and j have found lower and higher number than pivot 
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        }
    }while(i < j);
    // Swapping arr[low] and arr[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quick_sort(int* arr, int low, int high){
    int partition_index;
    if(low < high){
        traversal(arr, 9);
        partition_index = partition(arr, low, high); 
        quick_sort(arr, low, partition_index - 1);   // Sort left side array
        quick_sort(arr,  partition_index + 1, high); //Sort right side array
    }
}
int main(){
    int arr[] = {56,34,4,56,67,23,45,90,9};
    int size = sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, size - 1);
    traversal(arr, size);
    return 0;
}