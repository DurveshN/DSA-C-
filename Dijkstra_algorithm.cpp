#include <bits/stdc++.h>
#include <climits>
#include <vector>
#include <iterator>
using namespace std;
/*
Graph :-  () - Distance
    0  --(4)--  1
    |           |  \ (2)
    (2)         (3)  2
    |           |  /(8)
    4  --(2)--  3   
*/
#define infi 999
int v = 5; // Vertex of graph
//                        rows           colums  initalizing every element to infinity (infi)
vector<vector<int>> cost(v, vector<int>(v, infi)); // Vector of graph
vector<int> distance(v, infi); // Distance between nodes, at first distance between every node is infinity but source node is 0 as it is starting node
vector<bool> visited(v, false); // To track visited nodes
vector<int> parent(v, -1); // To track nodes from where it start and then which nodes it visited to reach shortest path
int source = 0; // source node (starting node also when algo starts)


int get_nearest_node(){
    int min_distance = infi; // Minimum distance between nodes
    int min_node = -1; // Node which has minimum distance from source node
    for(int i = 0; i < v; i++){
        if(!visited[i] && distance[i] < min_distance){ // Distance is infi but it is only 0 when node is source node
            min_distance = distance[i];
            min_node = i;
        }
    }
    return min_node;
}

void dijkstra(){
    for(int i = 0; i < v - 1; i++){ // For row traversal to find nearest node
        int nearest = get_nearest_node();
        if (nearest == -1) break; // All remaining nodes are unreachable
        visited[nearest] = true;

        for(int adj = 0; adj < v; adj++){ // For column traversal to find shortest distance
            if(!visited[adj] && cost[nearest][adj] != infi && distance[adj] > distance[nearest] + cost[nearest][adj]){
                distance[adj] = distance[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void display(){
    cout << "Node:\tCost:\tPath:\n";
    for(int i = 0; i < v; i++){
        if (i == source) continue;
        cout << i << "\t" << distance[i] << "\t";
        stack<int> path;
        int temp = i;
        while (temp != -1) {
            path.push(temp);
            temp = parent[temp];
        }
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " <- ";
        }
        cout << endl;
    }
}

int main(){
    // Making Graph :-
    cost[0][1] = 4;
    cost[0][4] = 2;
    cost[1][3] = 3;
    cost[1][2] = 2;
    cost[1][0] = 4;
    cost[2][1] = 2;
    cost[2][3] = 8;
    cost[3][2] = 8;
    cost[3][1] = 3;
    cost[3][4] = 2;
    cost[4][0] = 2;
    cost[4][3] = 2;
    distance[source] = 0; // As starting node should be 0
    dijkstra();
    display();
    return 0;
}
