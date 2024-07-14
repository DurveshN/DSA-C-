#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void traversal(node* head){
    node* ptr = head;
    do{
        cout<<"Element is : "<<ptr->data<<endl;
        ptr = ptr->next; 
    }while(ptr!=head);
}

// Circular Linked list insertion
// node* insertion(node* head, int data, int index){
//     node* ptr = new node;
//     ptr->data = data;
//     node* p = head;
//     if(index >= 5){
//         cout<<"Outoff range "<<endl;
//         return head;
//     }
//     if(index == 0){
//             do{
//                 p = p->next;
//             }while(p->next != head);
//             p->next = ptr;
//             ptr->next = head;
//             return ptr;
//     }
//     else{
//         for(int i = 0; i < (index-1); i++){
//             p = p->next;
//         }
//         ptr->next = p->next;
//         p->next = ptr;
//     }
//     return head;
// }

// Circular Linked list deletion 
// node* deletion(node* head, int index){
//     if(index >= 5){
//         cout<<"Outoff range "<<endl;
//         return head;
//     }
//     node* prev = head;
//     node* p = new node;
//     p = head->next;
//     if(index == 0){
//         while(p->next != head){
//             p = p->next;
//         }
//         p->next = prev->next;
//         return p->next;
//     }
//     for(int i = 0; i < (index-1); i++){
//         p = p->next;
//         prev = prev->next;
//     }
//     prev->next = p->next;
//     delete(p);
//     return head;
// }

int main(){
    node* head = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;
    node* fivth = new node;

    head->data = 15;
    head->next = second;
    second->data = 16;
    second->next = third;
    third->data = 18;
    third->next = fourth;
    fourth->data = 95;
    fourth->next = fivth;
    fivth->data = 10;
    fivth->next = head;

    cout<<"Circular Linked list before :"<<endl;
    traversal(head);
    
    // Insertion :-
    // head = insertion(head, 80, 6);
    // cout<<"Circular Linked list after insertion :"<<endl;
    // traversal(head);

    // Deletion :-
    // head = deletion(head, 4);
    // cout<<"Linked list after deletion"<<endl;
    // traversal(head);
    
    return 0;
}