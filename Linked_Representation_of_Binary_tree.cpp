#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
};

node* creatnode(int data){ // To create new node
    node* n = new node;  
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// For Binary search tree (BST)
//      27 (p)
//     /   \
//(p1)17    30(p2)
//    / \   / \
//   7  18 29  90
//  / \
// 6   9

// void preorder(node* root){ // Preorder traversal   root - left side- right side
//     if(root != NULL){
//         cout<<root->data<<" ";
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// void postorder(node* root){ // Postorder traversal  left side - right side - root
//     if(root != NULL){
//         postorder(root->left);
//         postorder(root->right);
//         cout<<root->data<<" ";
//     }
// }

void inorder(node* root){ // inorder traversal  left side - root - right side
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// int BST(node* root){ // Binary search tree
//     static node* prev = NULL; // static is used as when function is again called, prev does not set again to NULL, it remains last value which it was assigned.
//     if(root != NULL){
//         if(!BST(root->left)){ // Checks if left side of root follows BST or not. If it return 0, then this will also return 0 and BST does not apply.
//             return 0;
//         }
//         if(prev!= NULL && root->data <= prev->data){ // Checks for left side condition ( condition is root is bigger than left side element)
//             return 0;
//         }
//         prev = root; // As prev is previous element of root
//         return BST(root->right); // To check right side
//     }
//     else{
//         return 1;
//     }
// }

// void search_in_BST(node* root, int key){  // This search uses recurrsion
//     if(root == NULL){
//         cout<<"Element "<<key<<" does not exist in tree "<<endl;
//     }
//     else if(root->data == key){
//         cout<<"Element "<<key<<" exists in tree "<<endl;
//     }
//     else if(root->data > key){
//         search_in_BST(root->left, key);
//     }
//     else{
//         search_in_BST(root->right, key);
//     }
// }

// void search_in_BST_illertion(node* root, int key){  // This does not uses recusrrsion and does not take space in stack like in recurrsion
//     while(root!= NULL){
//         if(root->data == key){
//             cout<<"Element "<<key<<" exist in the tree "<<endl;
//             return;
//         }
//         else if(root->data > key){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     cout << "Element " << key << " does not exist in the tree." << endl;
// }

// void insertion(node* root, int key){ //Insertion only takes place in leaf node. you cannot insert at root or any parent node.
//     node* prev = NULL; // To track prev node whose next node is going to be new node(one to be inseted).
//     while(root != NULL){
//         prev = root;
//         if(root->data == key){
//             cout<<"Element "<<key<<" already exists in tree"<<endl;
//             return;
//         }
//         if(root->data > key){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     node* n = creatnode(key); // New node which is to be inserted. 
//     if(prev->data > key){
//         prev->left = n; 
//     }    
//     else{
//         prev->right = n;
//     }
// }

node* precedence(node* root){
    root = root->left; // We go first left as right side element are bigger than val
    while(root->right != NULL){ // After going one time left, rightmost element has to ne preceding element of val(you can check that preceding element is rightmost by print BST and see preceding element of val)
        root = root->right;
    }
    return root;
}
node* deletion(node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<"Deleting element "<<val<<endl;
        delete root;
        return NULL;
    }
    if(root->data > val){
        root->left = deletion(root->left, val);
    }
    else if(root->data < val){
        root->right = deletion(root->right, val);
    }
    else{
        node* ipre = precedence(root); // To find preceding element (element which is before the val which i to be deleted)
        root->data = ipre->data;
        root->left = deletion(root->left, ipre->data);
    }  
    return root; 
}
int main(){
// Creating tree 
    node* p = creatnode(27); //Root node
    node* p1 = creatnode(17); // Child Node left side
    node* p2 = creatnode(30); // Child Node right side
    p->left = p1;
    p->right = p2;

    node* p3 = creatnode(7); // Child Node p1 left side
    node* p4 = creatnode(18); // Child Node p1 right side
    p1->left = p3;
    p1->right = p4;

    node* p5 = creatnode(6); // Child Node p3 left side
    node* p6 = creatnode(9); // Child Node p3 right side
    p3->left = p5;
    p3->right = p6
    ;
    node* p7 = creatnode(29); // Child Node p2 left side
    node* p8 = creatnode(90); // Child Node p2 right side
    p2->left = p7;
    p2->right = p8;

    // Printing methods :-
    // cout<<"Preorder : ";
    // preorder(p);
    // cout<<endl;
    // cout<<"postorder : ";
    // postorder(p);
    // cout<<endl;
    // cout<<"inorder : ";
    // inorder(p);
    cout<<endl;
    //To check if BST
    // if(BST(p)){
    //     cout<<"This is BST "<<endl;
    // }
    // else{
    //     cout<<"This is not BST "<<endl;
    // }

    // Searching in BST 
    // search_in_BST(p, 4);
    // search_in_BST_illertion(p, 9);

    // Insertion
    // insertion(p, 28);

    // Deletion :-
    cout<<"inorder : ";
    inorder(p);
    deletion(p, 9);
    cout<<endl;
    cout<<"inorder : "<<endl;
    inorder(p);
    return 0;
}
