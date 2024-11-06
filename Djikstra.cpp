
        /*
        the * is the dereference operator. Here’s what it’s doing:
            st.begin() returns an iterator pointing to the first element in the set st.
            This iterator is not the element itself but a pointer-like object pointing to the element.
            * (dereference operator) accesses the value at the iterator's position, which is the actual element
            (a pair<int, int> in this case) stored in the set.
            So *(st.begin()) gets the first (smallest) element in the set by dereferencing the iterator returned by 
            st.begin() and stores it in top, which will hold the pair {nodeDistance, topNode}.
        */

       /*
       
       Actually, in this case, `top` is not an `int`; it’s a `std::pair<int, int>`, since `st` is a set of pairs:
        set<pair<int, int>> st; 

        The smallest element in `st` is a pair representing `{nodeDistance, topNode}`, not a single integer.
        So you would need to declare `top` with the full type if you don’t use `auto`:
        std::pair<int, int> top = *(st.begin());
        Using `auto` here simplifies the syntax without losing clarity, especially when working with
        data structures that use nested types like `std::pair` or iterators.

       */
#include <bits/stdc++.h> 

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create an adjacency list to store the graph
    unordered_map<int, list<pair<int, int>>> adj;

    // Populate the adjacency list with the given edges
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];  // Start vertex of the edge
        int v = vec[i][1];  // End vertex of the edge
        int w = vec[i][2];  // Weight of the edge

        // Since the graph is undirected, add an edge from u to v and from v to u
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Initialize distances with infinity (or a large number)
    vector<int> distance(vertices, INT_MAX);

    // Min-heap to store the vertices and their current shortest distance
    set<pair<int, int>> st;

    // Distance from source to source is 0
    distance[source] = 0;
    st.insert({0, source});

    // Main loop of Dijkstra's algorithm
    while (!st.empty()) {
        // Get the vertex with the smallest distance
        auto top = *(st.begin());
        int nodeDistance = top.first;  // Current shortest distance to the vertex
        int topNode = top.second;      // The vertex itself

        // Remove the vertex from the set as we are processing it now
        st.erase(st.begin());

        // Explore the neighbors of the current vertex
        for (auto neighbour : adj[topNode]) {
            int neighbourNode = neighbour.first;  // Neighbor vertex
            int weight = neighbour.second;        // Weight of the edge to the neighbor

            // If the path through the current vertex is shorter, update the distance
            if (nodeDistance + weight < distance[neighbourNode]) {

                // Remove old distance entry if it exists
                auto record = st.find({distance[neighbourNode], neighbourNode});
                
                if (record != st.end()) {
                    st.erase(record);
                }

                // Update the shortest distance to the neighbor
                distance[neighbourNode] = nodeDistance + weight;

                // Add the updated distance to the set
                st.insert({distance[neighbourNode], neighbourNode});
            }
        }
    }

    // Return the vector containing the shortest distance from source to all other vertices
    return distance;
}