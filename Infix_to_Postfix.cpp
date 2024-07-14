#include <iostream>
#include <string>
using namespace std;

class node{
    public:
    char data;
    node* next;
};
node* top = NULL;

int isempty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int isfull(){
    node* p = new node;
    if(p == NULL){
        return 1;
    }
    delete(p);
    return 0;
}
void push(char data){
    if(isfull()){
        cout<<"Stack overflow "<<endl;
    }
    else{
    node* p = new node;
    p->data = data;
    p->next = top;
    top = p;
    }
}

char pop(){
   if(isempty()){
        cout << "Stack underflow" << endl;
        return -1;
    }
    else {
        node* p = top;
        char data = p->data;
        top = top->next;
        delete p;
        return data;
    }
}

int isoperator(char data){
    if (data == '+' || data == '-' || data == '/' || data == '*' )
    {
       return 1;
    }
    return 0;
}

int precedence(char data){
    if(data == '*' || data == '/'){
        return 3;
    }
    if(data == '+' || data == '-'){
        return 2;
    }
    return 1;
}

char stacktop(){
    if(!isempty()){
    return top->data;
    }
    return '\0';
}


char* infix_postfix(string infix){
    int i = 0, j = 0;
    char* postfix = new char[infix.length() + 1];
    while(infix[i] != '\0'){
        if(!isoperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(stacktop()) < precedence(infix[i])){
                push(infix[i]);
                i++;
            }
            else{
                postfix[j] = pop();
                j++;    
            }
        }
    }
        while (!isempty()) {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    string infix;
    cout<<"Enter Equation : "<<endl;
    getline(cin, infix);
    char* postfix = infix_postfix(infix);
    cout << "Postfix of " << infix << " is: " << postfix << endl;
    delete[] postfix;
    return 0;
}