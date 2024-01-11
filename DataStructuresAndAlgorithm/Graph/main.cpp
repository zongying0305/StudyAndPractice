#include <iostream>
#include <vector>

void addEdge( std::vector<int>adj[], int src, int dest ) {
    adj[src].push_back( dest );
}

void printGraph( std::vector<int>adj[], int vertexNumer ) {
    for ( int i = 0; i < vertexNumer; ++i ) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for ( auto x : adj[i] )
            std::cout << x << ", ";
        std::cout << std::endl;
    }
}

void adjacencyListGraph() {
    const int vertexNumer = 5;
    std::vector<int> adj[vertexNumer];

    addEdge( adj, 0, 1 );
    addEdge( adj, 0, 4 );
    addEdge( adj, 1, 2 );
    addEdge( adj, 1, 3 );
    addEdge( adj, 1, 4 );
    addEdge( adj, 2, 3 );
    addEdge( adj, 3, 4 );

    printGraph( adj, vertexNumer );
}

class Node {
public:
    int data;
    Node* next;
};

class Edge {
public:
    Edge( int src, int dest ) {
        this->src = src;
        this->dest = dest;
    }
    int src;
    int dest;
};

class Graph {
public:
    Graph( Edge edges[], int edgeSize, int nodeNumber ) {
        this->nodeNumber = nodeNumber;
        head = new Node * [nodeNumber];
        memset( head, 0, sizeof( Node* ) * nodeNumber );

        for ( int i = 0; i < edgeSize; ++i ) {
            int src = edges[i].src;
            int dest = edges[i].dest;
            Node* newNode = getAdjListNode( dest, head[src] );
            head[src] = newNode;
        }
    }

    void printList( Node* ptr ) {
        while ( ptr != nullptr ) {
            std::cout << ptr->data << ",  ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

    Node** head;

private:
    Node* getAdjListNode( int dest, Node* head ) {
        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = head;
        return newNode;
    }

    int nodeNumber;
};

int main() {
    //adjacencyListGraph();

    Edge edges[] = {
        // pair (src, dest) represents edge from src to dest
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 3, 2 }, { 4, 5 }, { 5, 4 }
    };
    int edgeSize = sizeof( edges ) / sizeof( edges[0] );

    int nodeNuber = 6;

    Graph g( edges, edgeSize, nodeNuber );
    for ( int i = 0; i < nodeNuber; ++i ) {
        std::cout << i << ": ";
        g.printList( g.head[i] );
    }

    system( "pause" );
    return 0;
}