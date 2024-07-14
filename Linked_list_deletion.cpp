#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

void traversal(node* head){
    node* ptr = head;
    while(ptr!= NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

// Deletion in beginning
// node* deletion_in_beg(node* head){
//     node* ptr = head;
//     head = head->next;
//     free(ptr);
//     return head;
// }

// Deletion in between
// int deletion_in_bet(node* head, int index){
//     node* p = head;
//     for(int i = 0; i < (index - 1); i++){
//         if(p == NULL){
//             cout<<"Index is out of range "<<endl;
//             return 0;
//         }
//         p = p->next;
//     }
//     node* q = p->next;
//     p->next = q->next;
//     free(q);
// }

// Deletion at the end 
// void deletion_at_end(node* head){
//     node* p = head;
//     node* q = head->next;
//     while(q->next != NULL){
//         p = p->next;
//         q = q->next;
//     }
//     p->next = NULL;
//     free(q);
// }

// Deletion with the given value 
// node* deletion_with_value(node* head, int data){
//     node* p = head;
//     node* prev = NULL;
//     if(head->data == data){  
//         head = head->next;
//         free(p);
//         free(prev);
//         return head;
//     }
//     while(p->data != data && p != NULL){
//         prev = p;
//         p = p->next;
//     }
//     if(p == NULL){
//         cout<<"Value does not exist in linked list"<<endl;
//         return head;
//     }
//     prev->next = p->next;
//     free(p);
//     return head;
// }

int main(){
    node* head = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;
    node* fivth = new node;

    head->data = 17;
    head->next = second;
    second->data = 19;
    second->next = third;
    third->data = 10;
    third->next = fourth;
    fourth->data = 18;
    fourth->next = fivth;
    fivth->data = 109;
    fivth->next = NULL;

    cout<<"Linked list before insertion"<<endl;
    traversal(head);

    // Case 1 :- Deletion in the beginning
    // head = deletion_in_beg(head);
    // cout<<"Linked list after deletion in the beginning : "<<endl;
    // traversal(head);

    // Case 2 :- Deletion in between
    // int index = 2;
    // deletion_in_bet(head, index);
    // cout<<"Deletion in between :"<<endl;
    // traversal(head);

    // Case 3 :- Deletion at the end 
    // deletion_at_end(head);
    // cout<<"Deletion at the end :"<<endl;
    // traversal(head);

    // Case 4 :- Deletion with given value 
    // int data = 109;
    // head = deletion_with_value(head, data);
    // cout<<"Linked list after deletion with value : "<<endl;
    // traversal(head);

    return 0;
}