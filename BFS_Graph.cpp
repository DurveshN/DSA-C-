#include <iostream>
using namespace std;

class node{ 
    public:
    int data;
    node* next;
};
node* f = NULL;
node* r = NULL;

void traversal(){
    node* n = f;
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

int isempty(){
    if(f == NULL){
        return 1;
    }
    return 0;
}
int isfull(){
    node* n = new node;
    if(n == NULL){
        return 1;
    }
    delete n;
    return 0;
}

void enquene(int val){
    if(isfull()){
        cout<<"Graph Overflow "<<endl;
        return;
    }
    node* n = new node;
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

int dequene(){
    if(isempty()){
        cout<<"Graph underflow "<<endl;
        return -1;
    }
    node* n = new node;
    n = f;
    int val = f->data;
    f = f->next;
    delete n;
    return val;
}

/*
Graph :-
    0 - 1
    | \ |
    2   3
     \ /
      4
     / \
    5   6    
*/

int main(){
    int u;
    int i = 4;  // Starting number/node (can be any node from graphto start traversal) 
    int visited[7] = {0,0,0,0,0,0,0}; // Quene is formnexploration and vivisted to track visited
    int a [7][7] = {
        {0,1,1,1,0,0,0},  //0
        {1,0,0,1,0,0,0},  //1
        {1,0,0,1,1,0,0},  //2
        {1,1,1,0,1,0,0},  //3
        {0,0,1,1,0,1,1},  //4
        {0,0,0,0,1,0,0},  //5
        {0,0,0,0,1,0,0},  //6
    };
    cout<<i<<" ";
    visited[i] = 1;
    enquene(i); // enquene i for exploration
    while(!isempty()){
        u = dequene();
        for(int j = 0; j < 7; j++){  // To check every colomum in matrix like a[1][0](j = 0), a[1][1](j = 1), a[1][2](j = 2)
            if(a[u][j] == 1 && visited[j] ==0){ 
                cout<<j<<" ";  //Print j as j is the number in graph
                visited[j] = 1; // Adding that number in visited to ensure i is not printed twice
                enquene(j); // To check for exploration
            }
        }
    }
    return 0;
}