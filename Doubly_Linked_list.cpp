#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
};

void traversal(node* head){
    node* ptr = head;
    node* last = NULL;
    do{
        cout<<"Element is : "<<ptr->data<<endl;
        last = ptr;
        ptr = ptr->next;
    }while(ptr != NULL);

    cout<<"now in reverse order :"<<endl;
    ptr = last;
    do{
        cout<<"Element is : "<<ptr->data<<endl;
        ptr = ptr->prev;
    }while(ptr != NULL);
}

// Insertion :-
// node* insertion(node* head, int data, int index){
//     if(index > 4){
//         cout<<"Outoff range "<<endl;
//         return head;
//     }
//     node* p = head;
//     node* q = new node; 
//     q->data = data;
//     if(index == 0){
//         q->next = p;
//         p->prev = q;
//         q->prev = NULL;
//         return q;
//     }
//     if(index == 3){
//         while(p->next != NULL){
//             p = p->next;
//         }
//         p->next = q;
//         q->prev = p;
//         q->next = NULL;
//         return head;
//     }
//     for(int i = 0; i < (index - 1); i++){
//         p = p->next;
//     }
//     node* r = p->next;
//     q->next = r;
//     p->next = q;
//     q->prev = p;
//     r->prev = q;
//     return head;
// }


int main(){
    node* head = new node;
    node* second = new node;
    node* third = new node;
     
    head->data = 58;
    head->next = second;
    head->prev = NULL;
    
    second->data = 5;
    second->next = third;
    second->prev = head;

    third->data = 8;
    third->next = NULL;
    third->prev = second;

    cout<<"Doubly Linked list : "<<endl;
    traversal(head);

    // Insertion :-
    // cout<<"Doubly Linked list after insertion : "<<endl;
    // head = insertion(head,17,3);
    // traversal(head);

    return 0;
}