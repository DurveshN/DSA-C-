#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Graph :-  () - Distance
    0  --(4)--  1
    |           |  \ (2)
    (2)         (3)  2
    |           |  /(8)
    4  --(2)--  3   
*/
//                     rows           colums  initalizing every element to 0
vector <vector<int>> G (5, vector<int> (5,     0)); // Vector of graph

void display(){
    cout<<"Graph in matrix form : "<<endl;
    for(auto i:G){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Shortest_distance(vector<int> &distance){
    int count = 0;
    for(int i = 0; i < distance.size(); i++){
        count = count + distance[i];
    }
    cout<<"Shortest distance is :"<<count<<endl;
}

int main(){
    // Making Graph :-
    G[0][1] = 4;
    G[0][4] = 2;
    G[1][3] = 3;
    G[1][2] = 2;
    G[1][0] = 4;
    G[1][0] = 4;
    G[2][1] = 2;
    G[2][3] = 8;
    G[3][2] = 8;
    G[3][1] = 3;
    G[3][4] = 2;
    G[4][0] = 2;
    G[4][3] = 2;
    display();

    int vertex = 5; // Vertex
    int edges = 0;
    vector <int> distance (vertex - 1, 0); // To store distance
    int d = 0; // Index of distance vector
    vector <bool> visited (vertex, false); // This vector is for visited, false means nit visited yet, true means visited
    visited[0] = true;
    while(edges < vertex - 1) { // For number of edges to make minimum spanning tree, we need edges = vertex - 1
        int min = INT_MAX;
        int r =0,c=0; // r = rows, c = column
        for(int i = 0; i <= vertex; i++){ // To traveral rows
            if(visited[i]){ // To check whether it is true or false in visited vector, if true, then we should visit it.
                for(int j = 0; j <= vertex; j++){ // To treaveral column
                    if(!visited[j] && (G[i][j] != 0) && (G[i][j] < min)){ // To get min and G != 0 as 0 cant be min and visited[j] should not be true {lets understand why it shoud be false: if min distance between 0 and 4 was 1. So during search of node, we shouldnt consider again distance of 0 and 4. To avoid this, we used this condition}
                        min = G[i][j];
                        r = i;
                        c = j;
                    }
                }
            }   
        }
        visited[c] = true;
        distance[d] = min;
        d++;
        edges++;
    }
    Shortest_distance(distance);
    return 0;
}

