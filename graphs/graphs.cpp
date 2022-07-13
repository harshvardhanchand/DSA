#include <iostream>
#include <queue>
using namespace std;

// Graphs are of muliple types: directed, undirected, weighted, unweighted, cyclic, acyclic
// Simple digraph is a graph with no loops and no multiple edges
// Strongly connected graph is a graph from which you can reach all vertices from one  vertex
// An undirected graph can be represented in 3 ways
// 1. Adjacency matrix
// 2. Adjacency list
// 3.Compact list
// 1.Adjacency matrix: we create a matrix of size nxn and we fill it with 0s and 1s n is number of vertices O(n^2)
// if a vertex is connected to another vertex then we put 1 in the matrix  like if 1 is connected to 2 we put A[i][j] = 1
// 2.Adjacency list: we create a list of vectors and we fill it with 0s and 1s if a vector is connected to another vector we put 1 in the list i.e an array of linked list
// O(n+2m) m no.of edges and n no.of vertices
// we can also store weights instead of 0 s and  1s
// 3.Compact list: we create an array of size n+2m+1  we leave 0 vacant, this is actually to lengthy to write just look it up

// A directed graph can be represented in multiple ways
// 1. Adjacency matrix
// 2. Adjacency list
// 3. Adjacency matrix with edge weights

// 1 we only take the edge from one vertex to another vertex i.e which is directed from one vertex to another not vice versa
// 2.Same with adjacency list

// B.F.S of a graph: it is same as level order traversal of a tree (trees are a type of graph)

// B.F.S there are two concepts
// 1. BFS: Breadth first search is a type of traversal that starts at the root and explores the neighbor nodes first before moving to the next level.
// 1.Visiting: we visit a node and we mark it as visited
//  2.Exploration:we explore all adjacent nodes of visited vertex
// We use a queue to implement BFS
// we vist a node,put it in queue explore it put all visited nodes in queue once node is fully visited deque it and explore it's adjacent nodes and so on
void BFS(int vtx, int A[][8], int n)
{
    queue<int> Q;
    int visited[8]{0};

    // Initial
    cout << vtx << ", " << flush; // Visit vertex
    visited[vtx] = 1;
    Q.emplace(vtx);

    // Explore
    while (!Q.empty())
    {
        int u = Q.front(); // Vertex u for exploring
        Q.pop();
        for (int v = 1; v <= n; v++)
        { // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0)
            {                               // Adjacent vertex and not visited
                cout << v << ", " << flush; // Visit vertex
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}

int main()
{

    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);

    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);

    return 0;
}
