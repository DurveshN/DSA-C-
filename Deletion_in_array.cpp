#include <iostream>
using namespace std;

void traversal(int arr[], int size){
    // traversal code 
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<endl;
    }
}

int deletion(int arr[], int size, int element){
    // Deletion code 
    int index;
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            index = i;
            break;
        }
    }
    for( int j = index; j < (size-1); j++){
        arr[j] = arr[j+1];
    }
    return index;
}
int main(){
    int arr[] = {7,14,15,45,56};
    int size = sizeof(arr)/sizeof(int);
    int capacity = 10;
    traversal(arr, size);
    int element = 15;
    int index = deletion(arr, size, element);
    size -= 1;
    cout<<endl;
    traversal(arr, size);
    cout<<"Deleted element index was :"<<index;
    return 0;
}