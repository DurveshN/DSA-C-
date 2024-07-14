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

// insertion at the beginning
// node* insertion_beg(node* head, int data){
//     node* ptr = new node;
//     ptr->data = data;
//     ptr->next = head;
//     return ptr;
// }

// insertion in between
// node* insertion_in_betw(node* head, int data, int index){
//     node* ptr = new node;
//     node* p = head;
//     if(index == 0){
//         ptr->data = data;
//         ptr->next = head;
//         return ptr;
//     }
//     for(int i = 0; i < (index-1); i++){
//         if(p->next == NULL){
//             cout<<"Index is outof range"<<endl;
//             free(ptr);
//             return head;
//         }
//         p = p->next;
//     }
//     ptr->data = data;
//     ptr->next = p->next;
//     p->next = ptr; 
//     return head;
// }

// insertion at the end 
// void insertion_at_end(node* head, int data){
//     node* p = head;
//     node* ptr = new node;
//     while(p->next != NULL){
//         p = p->next;
//     }
//     ptr->data = data;
//     p->next = ptr;
//     ptr->next = NULL;
// }

// insertion in node 
// void insertion_in_node(node* third, int data){
//     node* ptr = new node;
//     ptr->data = data;
//     ptr->next = third->next;
//     third->next = ptr;
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

// --------------------------------------------------------------------------------------------------------------------------------------------
    // Case 1 :- insertion at the beginning
    // int data = 90;
    // head = insertion_beg(head, data);
    // cout<<"Insertion at the beginning :"<<endl;
    // traversal(head);

// --------------------------------------------------------------------------------------------------------------------------------------------
    // Case 2 :- insertion in between
    // int data = 90;
    // int index = 1;
    // head = insertion_in_betw(head, data, index);
    // cout<<"Linked list insertion in between :"<<endl;
    // traversal(head);

// --------------------------------------------------------------------------------------------------------------------------------------------
//     Case 3 :- insertion at the end
//     int data = 90;
//     insertion_at_end(head, data);
//     cout<<"Insertion at the end :"<<endl;
//     traversal(head);
// --------------------------------------------------------------------------------------------------------------------------------------------
    
//     Case 4 :- insertion in node 
    // int data = 90;
    // insertion_in_node(third, data);
    // cout<<"Insertion in node :"<<endl;
    // traversal(head);
// --------------------------------------------------------------------------------------------------------------------------------------------
    return 0;
}