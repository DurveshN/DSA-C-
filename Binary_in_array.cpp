#include <iostream>
using namespace std;

int binary(int arr[], int size, int element){
    // Binary Search 
    int low,mid,high;
    low = 0;
    high = size-1;
    while(low <= high){
        mid = (high + low)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,3,6,11,34,56,78};
    int size = sizeof(arr)/sizeof(int);
    int element = 3;
    int index = binary(arr, size, element);
    cout<<"Index is : "<<index<<endl;
    return 0;
}