#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
node* r = NULL;
node* f = NULL;

void traversal(){
    node* ptr = f;
    while(ptr!= NULL){
        cout<<"Element is : "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    delete(ptr);
}
void enquene(int val){
    node* n = new node;
    if(n == NULL){
        cout<<"Quene Overflow "<<endl;
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}

int dequene(){
    if(f == NULL){
        cout<<"Quene Underflow "<<endl;
        return -1;
    }
    node* n = new node;
    n = f;
    int val = f->data;
    f = f->next;
    delete(n);
    return val;
}

int main(){
    enquene(57);
    enquene(97);
    enquene(7);
    traversal();
    cout<<"Dequened element is : "<<dequene()<<endl;
    cout<<"Dequened element is : "<<dequene()<<endl;
    cout<<"Dequened element is : "<<dequene()<<endl;
    cout<<"Dequened element is : "<<dequene()<<endl;
    return 0;
}