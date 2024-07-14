// This is one way to do by making top as global variable;
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
node* top = new node;
int isempty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int isfull(){
    node* n = new node;  // Create new node if you want full dynamic memory. Else you can specify also how much size you want.
    if(n == NULL){       
        return 1;
    }
    return 0;
}

void traversal(){
    node* p = top;
    while(p != NULL){
        cout<<"Element is : "<<p->data<<endl;
        p = p->next;
    }
}

void push(int data){
    if(isfull()){
        cout<<"Stack Overflow "<<endl;
    }
    else{
    node* p = new node;
    p->data = data;
    p->next = top;
    top = p;
    }
}

int pop(node* tp){
    if(isempty()){
        cout<<"Stack underflow "<<endl;
        return -1;
    }
    node* p = tp;
    top = p->next;
    int x = p->data;
    delete(p);
    return x;
}

int stack_top(){
    return top->data;
}

int stack_bottom(){
    node* p = top;
    while(p->next != NULL){
        p = p->next;
    }
    return p->data;
}

int peek(int index){
    node* p = top;
    for(int i = 0; (i < index -1 && p != NULL); i++){
        p = p->next;
    }
    return p->data;
}

int main(){
    top = NULL;
    push(89);
    push(9);
    push(8);
    push(38);
    push(84);
    traversal();
    cout<<"poped element is : "<<pop(top)<<endl;
    traversal();
    cout<<"Stack top is : "<<stack_top()<<endl;
    cout<<"Stack bottom is : "<<stack_bottom()<<endl;
    
    cout<<"Stack peek is : "<<peek(2)<<endl;
    return 0;
}

// This is one way to do by sending top as pointer to allow changes in pop function.
// #include <iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;
// };

// int isempty(node* top){
//     if(top == NULL){
//         return 1;
//     }
//     return 0;
// }

// int isfull(){
//     node* n = new node;  // Create new node if you want full dynamic memory. Else you can specify also how much size you want.
//     if(n == NULL){       
//         return 1;
//     }
//     return 0;
// }

// void traversal(node* top){
//     node* p = top;
//     while(p != NULL){
//         cout<<"Element is : "<<p->data<<endl;
//         p = p->next;
//     }
// }
// node* push(node* top, int data){
//     if(isfull()){
//         cout<<"Stack Overflow "<<endl;
//         return top;
//     }
//     node* p = new node;
//     p->data = data;
//     p->next = top;
//     return p;
// }
// int pop(node** top){
//     if(isempty(*top)){
//         cout<<"Stack underflow "<<endl;
//         return -1;
//     }
//     node* p = *top;
//     *top = p->next;
//     int x = p->data;
//     delete(p);
//     return x;
// }
// int main(){
//     node* top = new node;
//     top = NULL;

//     top = push(top, 89);
//     top = push(top, 9);
//     top = push(top, 8);
//     traversal(top);
//     cout<<"poped element is : "<<pop(&top)<<endl;
//     traversal(top);
//     return 0;
// }