#include <iostream>
using namespace std;

void traversal(int arr[], int use){
    // traversal code 
    for (int i = 0; i <= (use -1); i++){
        cout<<arr[i]<<endl;
    }
}

int insert(int arr[], int size, int use, int element , int index){
    // insertion code 
    if(size <= use){
        cout<<"Array is full"<<endl;
        return -1;
    }
    for(int i = (use -1); i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 0;
}
int main(){
    int arr[10] = {7,27,18,19};
    int size = 10;
    int use = 4;
    int element = 25;
    int index = 2;
    traversal(arr, use);
    insert(arr, size, use, element, index);
    use += 1;
    traversal(arr, use);
    return 0;
}