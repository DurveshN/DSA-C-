#include <iostream>
using namespace std;

void linear(int arr[], int size, int element, int index[], int &count){
    // linear Searching
    count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            index[count] = i;
            count += 1;
        }
    }
}

int main() {
    int arr[] = {2, 67, 45, 78, 3, 56, 78, 78};
    int size = sizeof(arr) / sizeof(int);
    int element = 78;
    int index[10];
    int count;

    linear(arr, size, element, index, count);

    cout << element << " repeated: " << count << " times at positions: ";
    for (int i = 0; i < count; i++) {
        cout << index[i] << " ";
    }
    cout << endl;

    return 0;
}
