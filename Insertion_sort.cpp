#include <iostream>
using namespace std;

void traversal(int* arr, int size){
    for (int i = 0; i < size; i++)
    {
       cout<<arr[i]<<" ";
    }  
}

void insertion_sort(int* arr, int size){  
    int key;
    int j;                                                   // 0  1  2  3  4  5
    for(int i = 1; i < size; i++){  //Number of passes          56|03 45 78 09 45
        cout<<"This is "<<i<<" pass"<<endl;
        key = arr[i];
        j = i - 1;
        while(j >=0 && arr[j] > key){     //For swapping
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[] = {56, 3, 45, 78, 9, 45};
    int size  = sizeof(arr)/sizeof(int);
    insertion_sort(arr, size);
    traversal(arr, size);
    return 0;
}