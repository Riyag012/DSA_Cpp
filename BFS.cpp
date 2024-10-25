#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
#include <vector>

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int,int>> &edges){
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second; 

        adjList[u].push_back(v);
        adjList[v].push_back(u); //undirected graph
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;

    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // store front node to ans vector
        ans.push_back(frontNode);

        // adding all neighbours into queue;
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

// vector<int> bfsTraversal(int n, vector<vector<int>> &adjList){
//     // Write your code here.
//     unordered_map<int, bool> visited;
//     vector<int> ans;

//     //given that the breadth first traversal is starting form 0
//     bfs(adjList, ans, visited, 0); 

//     return ans;
// }

vector<int> BFS(int vertex, vector<pair<int,int>> edges){

    vector<int> ans;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    //traverse all components of a graph
    for (int i = 0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }


}