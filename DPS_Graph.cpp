#include <iostream>
using namespace std;

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
// Making Gobal to acess easily
int visited[7] = {0,0,0,0,0,0,0};
int a [7][7] = {
    {0,1,1,1,0,0,0},  //0
    {1,0,0,1,0,0,0},  //1
    {1,0,0,1,1,0,0},  //2
    {1,1,1,0,1,0,0},  //3
    {0,0,1,1,0,1,1},  //4
    {0,0,0,0,1,0,0},  //5
    {0,0,0,0,1,0,0},  //6
};

int DFS(int i){
    cout<<i<<" "; // i changes everytime
    visited[i] = 1; // To update visited
    for(int j = 0; j < 7; j++){
        if(a[i][j] == 1 && !visited[j]){
            DFS(j); // To reach end of every connection
        }
    }
}
int main(){
    DFS(1);
    return 0;
}