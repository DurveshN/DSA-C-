#include <iostream>
using namespace std;

class ADT_array{
    public:
        int size_of_array;
        int used_size;
        int* ptr;
};

void setdata(ADT_array &array){
    cout<<"Enter size of array : "<<endl;
    cin>>array.size_of_array;
    array.used_size = 10;
    array.ptr = new int[array.size_of_array]; 
    for(int i= 0; i <= (array.used_size - 1); i++){
        cout<<"Enter "<<i+1<<" element :";
        cin>>array.ptr[i];
    }
}

int main(){
    ADT_array array;
    setdata(array);
    return 0;
}
