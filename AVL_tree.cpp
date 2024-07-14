#include <iostream>
using namespace std;

class node{
    public:
    int data;
    int height;
    node* right;
    node* left;
};

node* create_node(int key){
    node* n = new node;
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int getheight(node* n){ // Gives height of node
    if(n == NULL){
        return 0;
    }
    return n->height;
}

int bf(node* n){ // Balance factor
    if(n == NULL){
        return 0;
    }
    return getheight(n->left) - getheight(n->right); 
}

int max(int a,int b){ // Give maxmimum height between left or right node
    if(a <= b ){
        return b;
    }
    return a;
}

/*
This is rough diagram for LL, y is unbalanced.
        y                    x
       / \                 /  \ 
      x   t3   ------->   t1   y
     / \                  /   / \
    t1  t2               t4  t2  t3
    /
   t4(inserted element which is causing problem)
*/
node* LL_rotation(node* y){ // Rotate to right side (clock wise)
    node* x = y->left; // Initalizing x
    node* t2 = x->right; // Initalizing t2 as it is going to get attach with y
    x->right = y;
    y->left = t2;

    x->height = max(getheight(x->left),getheight(x->right)) + 1;
    y->height = max(getheight(y->left),getheight(y->right)) + 1;
    return x; // Returning new root which is x now.
}

/*
This is rough diagram for RR, x is unbalanced.
        x                    y
       / \                 /  \ 
      t1  y   ------->    x    t3
         / \             / \     \
        t2  t3          t1  t2    t4
             \
              t4(inserted element which is causing problem)
*/
node* RR_rotation(node* x){ // Rotate to left side (anti clock wise)
    node* y = x->right; // Initalizing y
    node* t2 = y->left; // Initalizing t2 as it is going to get attach with x
    y->left = x;
    x->right = t2;
    x->height = max(getheight(x->left),getheight(x->right)) + 1;
    y->height = max(getheight(y->left),getheight(y->right)) + 1;
    return y; // Returning new root which is y now.
}

// This is diagram for LR :- (First left rotation [between 16 and 17] and then right rotation [ between 10,16,17])
/*
        7                           7                           7
       / \                         / \                         / \                    
      1   10                      1   10                      1   16
            \      ------->             \      ------->          / \ 
             17                          16                     10  17
             /                             \ 
            16(inserted element              17    
            causing problem)
*/

// This is diagram for RL :- (First right rotation [between 1 and 7] and then left rotation [ between 10,1,7])
/*
          16                        16                              16
         /  \                      /  \                            /  \ 
        10   17   ------->        10   17      ------->           7    17
       /                         /                               / \   
      1                         7                               1   10
       \                       /   
        7                     1    
*/


node* insert(node* n, int key){
    if(n == NULL){
       return create_node(key); // When root is null ( root does not exist)
    }
    if(key < n->data){
        n->left = insert(n->left, key);
    }
    else{
        n->right = insert(n->right, key);
    }
    n->height = 1 + max(getheight(n->left),getheight(n->right)); // For increment of height of all nodes as recurssively function is going to be get called starting from newly created leaf node
    // For LL rotation :-
    if(bf(n)>1 && key < n->left->data){
        return LL_rotation(n);
    }
    // For RR rotation :-
    if(bf(n)< -1 && key > n->right->data){
        return RR_rotation(n);
    }
    // For LR rotation :-
    if(bf(n)>1 && key > n->left->data){
        n->left = RR_rotation(n);
        return LL_rotation(n);
    }
    // For RL rotation :-
    if(bf(n)< -1 && key < n->right->data){
        n->right = LL_rotation(n);
        return RR_rotation(n);
    }
    return n;
}

void preorder(node* root){ // Preorder traversal   root - left side- right side
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root){ // Postorder traversal  left side - right side - root
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void inorder(node* root){ // inorder traversal  left side - root - right side
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main(){
    node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    preorder(root);
    return 0;
}