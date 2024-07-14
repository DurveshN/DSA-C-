#include <iostream>
#include <string>
using namespace std;

class node{
    public:
    char data;
    node* next;
};
node* top = new node;

int isfull(){
    node* p = new node;
    if(p == NULL){
        return 1;
    }
    return 0;
}

int isempty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}
void push(int data){
    if(isfull()){
        cout<<"Stack overflow "<<endl;
    }
    node* p = new node;
    p->data = data;
    p->next = top;
    top = p;
}

char pop(node* tp){
   if(isempty()){
        cout<<"Stack is empty "<<endl;
    }
    char x;
    node* p = new node;
    p = tp;
    top = p->next;
    x = p->data;
    delete(p);
    return x;
}

int match(char a, char b){
    if( (a == '{' && b == '}') || ( a == '[' && b == ']') || ( a == '(' && b == ')') ){
        return 1;
    }
    return 0;
}
void parenthesis(string equ){
    int i = 0;
    char poped;
   while( equ[i] != '\0'){
    if (equ[i] == '(' || equ[i] == '[' || equ[i] == '{')
    {
        push(equ[i]);
    }
    else if(equ[i] == ')' || equ[i] == ']' || equ[i] == '}'){
        if(isempty()){
            cout<<"Equation is incorrect "<<endl;
        }
        else{
            poped = pop(top);
            if(!match(poped, equ[i])){
                cout<<"Equation is incorrect "<<endl;
                break;
            }
        }
    }
    i++;
   }
   if(isempty()){
        cout<<"Equation is correct "<<endl;
   }
   else{
    cout<<"Equation is incorrect "<<endl;
   }
}
int main(){
    top = NULL;
    string equ;
    cout<<"Enter equation : "<<endl;
    getline(cin, equ);
    parenthesis(equ);
    return 0;
}