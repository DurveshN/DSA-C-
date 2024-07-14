#include <iostream>
using namespace std;

// void bubble_sort(int* arr, int size){  // This is not Adaptive (means does all the passes eventho it sorted)
//     int temp;
//     for(int i = 0; i < size; i++){ // for number of passes 
//         for(int j = 0; j < size-1-i; j++){ //for number of swaps
//             if(arr[j] > arr[j+1]){
//                 temp = arr[j+1];
//                 arr[j+1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

int bubble_sort(int* arr, int size){ // This is Adaptive
    int temp;
    int swap = 0;
    for(int i = 0; i < size; i++){ // for number of passes 
        swap = 1;
        cout<<"Number of pass : "<<i<<endl;
        for(int j = 0; j < size-1-i; j++){ //for number of swaps
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swap = 0;
            }
        }
        if(swap){
            return 1;
        }
    }
}

void traversal(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout<<" "<<arr[i];
    }
}
int main(){
    int arr[] = {1,2,4,3,5,6};
    int size = sizeof(arr)/sizeof(int);
    bubble_sort(arr, size);
    traversal(arr, size);
    return 0;
}