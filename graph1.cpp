#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
// template <typename T>
// replace T with int<datatype>

class Graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool dir){
        adj[u].push_back(v);

        if (dir==0){
            adj[v].push_back(u);
        }
    }

    void displayAdjList(){
        for(auto i: adj){
            cout<<i.first<<": ";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }

    }
};

int main(){
    int n;
    cout << "Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    Graph g;

    for (int i=0; i<m; i++) {
        int u, v;
        cout<<"Enter the edge : ";
        cin>>u>>v;

        g.addEdge(u, v, 0);
    }

    g.displayAdjList();

    return 0;
}