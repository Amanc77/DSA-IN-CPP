#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;

    // Add edge between u and v
    // direction = 0 => undirected, direction = 1 => directed
    void addEdge(T u, T v, bool direction) {
        adjList[u].push_back(v);
        if(direction == 0) {
            adjList[v].push_back(u);
        }
    }

    // Print the adjacency list
    void printAdjList() {
        cout << "\nAdjacency List:\n";
        for(auto &node : adjList) {
            cout << node.first << " -> ";
            for(auto &nbr : node.second) {
                cout << nbr << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }

    // BFS Traversal from a source node
    void bfs(T src, unordered_map<T, bool> &visited) {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            T front = q.front();
            q.pop();
            cout << front << " ";

            // Visit neighbors
            for(auto &nbr : adjList[front]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    // Perform BFS for all disconnected components
    void bfsAll() {
        unordered_map<T, bool> visited;
        cout << "\nBFS Traversal:\n";
        for(auto &node : adjList) {
            if(!visited[node.first]) {
                bfs(node.first, visited);
                cout << "\n";
            }
        }
    }

    // DFS Traversal from a source node
    void dfs(T src, unordered_map<T, bool> &visited) {
        visited[src] = true;
        cout << src << " ";

        for(auto &nbr : adjList[src]) {
            if(!visited[nbr]) {
                dfs(nbr, visited);
            }
        }
    }

    // Perform DFS for all disconnected components
    void dfsAll() {
        unordered_map<T, bool> visited;
        int componentCount = 0;

        cout << "\nDFS Traversal:\n";
        for(auto &node : adjList) {
            if(!visited[node.first]) {
                componentCount++;
                cout << "Component " << componentCount << ": ";
                dfs(node.first, visited);
                cout << "\n";
            }
        }
        cout << "Total Connected Components: " << componentCount << "\n";
    }

    // Find shortest path from src to dest using BFS (for unweighted graph)
    void shortestPath(T src, T dest) {
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src; // root has itself as parent

        while(!q.empty()) {
            T front = q.front();
            q.pop();

            for(auto &nbr : adjList[front]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    parent[nbr] = front;
                    q.push(nbr);
                }
            }
        }

        // Reconstruct path
        vector<T> path;
        if(!visited[dest]) {
            cout << "\nNo path exists from " << src << " to " << dest << "\n";
            return;
        }

        T current = dest;
        while(current != src) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());

        cout << "\nShortest Path from " << src << " to " << dest << ": ";
        for(auto &node : path) {
            cout << node << " ";
        }
        cout << "\n";
    }
};

int main() {
    Graph<char> g;

    // Create graph
    g.addEdge('a', 'b', 0);
    g.addEdge('a', 'c', 0);
    g.addEdge('b', 'd', 0);
    g.addEdge('c', 'e', 0);
    g.addEdge('e', 'f', 0);
    g.addEdge('g', 'h', 0); // Disconnected component

    g.printAdjList();

    g.bfsAll();  // BFS for all components
    g.dfsAll();  // DFS + count components

    g.shortestPath('a', 'f'); // Find shortest path

    return 0;
}
