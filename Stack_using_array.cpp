#include <iostream>
using namespace std;

class stack{
    public:
    int size;
    int top;
    int * arr;
};

int isempty(stack* s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

int isfull(stack* s){
    if(s->top == s->size - 1){
        return 1;
    }
    return 0;
}

void push(stack* s, int value){
    if(isfull(s)){
        cout<<"Stack Overflow "<<endl;
    }
    else{
        s->top += 1;
        s->arr[s->top] = value;
    }
}

int pop(stack* s){
    if(isempty(s)){
        cout<<"Stack is empty "<<endl;
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}


int stack_bottom(stack* s){
    if(isempty(s)){
        return -1;
    }
    return s->arr[0];
}

int stack_top(stack* s){
    if(isempty(s)){
        return -1;
    }
    return s->arr[s->top];
}

int peek(stack* s, int i){
    int index = s->top - i + 1;
    if(index < 0){
        return -1;
    }
    return s->arr[index];
}

int main(){
    stack* s = new stack;
    s->size = 5;
    s->top = -1;
    s->arr = new int[s->size];

    push(s, 5);
    push(s, 6);
    push(s, 56);

    // cout<<"Poped element is : "<<pop(s)<<endl;
    
    // Traversal :-
    for(int i = 1; i <= s->top + 1; i++){
    cout<<"Element at "<<i<<" is : "<<peek(s, i)<<endl;;
    }

    cout<<"Stack bottom is : "<<stack_bottom(s)<<endl;
    cout<<"Stack top is : "<<stack_top(s)<<endl;
    return 0;
}