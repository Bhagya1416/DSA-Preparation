#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <time.h> 
#define MAX_VERTICES 100 
#define INF INT_MAX 
// Adjacency Matrix Representation 
typedef struct { 
    int vertices; 
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; 
} GraphMatrix; 
// Adjacency List Representation 
typedef struct Node { 
    int vertex; 
    int weight; 
    struct Node* next; 
} Node; 
typedef struct { 
    int vertices; 
    Node* adjList[MAX_VERTICES]; 
} GraphList; 
// Function to create a graph using adjacency matrix 
GraphMatrix* createGraphMatrix(int vertices) { 
    GraphMatrix* graph = (GraphMatrix*)malloc(sizeof(GraphMatrix)); 
    graph->vertices = vertices; 
    for (int i = 0; i < vertices; i++) { 
        for (int j = 0; j < vertices; j++) { 
            graph->adjMatrix[i][j] = (i == j) ? 0 : INF; 
        } 
    } 
    return graph; 
} 
// Function to create a graph using adjacency list 
GraphList* createGraphList(int vertices) { 
    GraphList* graph = (GraphList*)malloc(sizeof(GraphList)); 
    graph->vertices = vertices; 
    for (int i = 0; i < vertices; i++) { 
        graph->adjList[i] = NULL; 
    } 
    return graph; 
} 
// Function to add edge to adjacency matrix 
void addEdgeMatrix(GraphMatrix* graph, int src, int dest, int weight) { 
    graph->adjMatrix[src][dest] = weight; 
    graph->adjMatrix[dest][src] = weight; // For undirected graph 
} 
// Function to add edge to adjacency list 
void addEdgeList(GraphList* graph, int src, int dest, int weight) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->vertex = dest; 
    newNode->weight = weight; 
    newNode->next = graph->adjList[src]; 
    graph->adjList[src] = newNode; 
    newNode = (Node*)malloc(sizeof(Node)); 
    newNode->vertex = src; 
    newNode->weight = weight; 
    newNode->next = graph->adjList[dest]; 
    graph->adjList[dest] = newNode; // For undirected graph 
} 
// Dijkstra's Algorithm using adjacency matrix 
void dijkstraMatrix(GraphMatrix* graph, int start) { 
    int dist[MAX_VERTICES]; 
    int visited[MAX_VERTICES] = {0}; 
    for (int i = 0; i < graph->vertices; i++) { 
        dist[i] = INF; 
    } 
    dist[start] = 0; 
    for (int count = 0; count < graph->vertices - 1; count++) { 
        int minDist = INF, minIndex; 
        for (int v = 0; v < graph->vertices; v++) { 
            if (!visited[v] && dist[v] <= minDist) { 
                minDist = dist[v]; 
                minIndex = v; 
            } 
        } 
        visited[minIndex] = 1; 
        for (int v = 0; v < graph->vertices; v++) { 
            if (!visited[v] && graph->adjMatrix[minIndex][v] != INF &&  
                dist[minIndex] + graph->adjMatrix[minIndex][v] < dist[v]) { 
                dist[v] = dist[minIndex] + graph->adjMatrix[minIndex][v]; 
            } 
        } 
    } 
    printf("Distances from source %d (Adjacency Matrix):\n", start); 
    for (int i = 0; i < graph->vertices; i++) { 
        printf("Vertex %d: %d\n", i, dist[i]);  
 
    } 
} 
// Dijkstra's Algorithm using adjacency list 
void dijkstraList(GraphList* graph, int start) { 
    int dist[MAX_VERTICES]; 
    int visited[MAX_VERTICES] = {0}; 
 
    for (int i = 0; i < graph->vertices; i++) { 
        dist[i] = INF; 
    } 
    dist[start] = 0; 
 
    for (int count = 0; count < graph->vertices - 1; count++) { 
        int minDist = INF, minIndex; 
 
        for (int v = 0; v < graph->vertices; v++) { 
            if (!visited[v] && dist[v] <= minDist) { 
                minDist = dist[v]; 
                minIndex = v; 
            } 
        } 
        visited[minIndex] = 1; 
        Node* temp = graph->adjList[minIndex]; 
        while (temp != NULL) { 
            if (!visited[temp->vertex] && dist[minIndex] + temp->weight < dist[temp->vertex]) { 
                dist[temp->vertex] = dist[minIndex] + temp->weight; 
            } 
            temp = temp->next; 
        } 
    } 
    printf("Distances from source %d (Adjacency List):\n", start); 
    for (int i = 0; i < graph->vertices; i++) { 
        printf("Vertex %d: %d\n", i, dist[i]); 
    } 
} 
int main() { 
    int vertices = 5; // Adjust the number of vertices as needed 
    GraphMatrix* graphMatrix = createGraphMatrix(vertices); 
    GraphList* graphList = createGraphList(vertices); 
    // Add edges (for example) 
    addEdgeMatrix(graphMatrix, 0, 1, 10); 
    addEdgeMatrix(graphMatrix, 0, 4, 5); 
    addEdgeMatrix(graphMatrix, 1, 2, 1); 
    addEdgeMatrix(graphMatrix, 2, 3, 4); 
    addEdgeMatrix(graphMatrix, 3, 0, 7); 
    addEdgeMatrix(graphMatrix, 4, 1, 3); 
    addEdgeMatrix(graphMatrix, 4, 2, 9); 
    addEdgeMatrix(graphMatrix, 4, 3, 2); 
    addEdgeList(graphList, 0, 1, 10); 
    addEdgeList(graphList, 0, 4, 5); 
    addEdgeList(graphList, 1, 2, 1); 
    addEdgeList(graphList, 2, 3, 4); 
    addEdgeList(graphList, 3, 0, 7); 
    addEdgeList(graphList, 4, 1, 3); 
    addEdgeList(graphList, 4, 2, 9); 
    addEdgeList(graphList, 4, 3, 2); 
    clock_t start, end; 
    // Measure time for adjacency matrix 
    start = clock(); 
    dijkstraMatrix(graphMatrix, 0); 
    end = clock(); 
    printf("Time taken for Adjacency Matrix: %lf seconds\n", (double)(end - start) / 
CLOCKS_PER_SEC); 
    // Measure time for adjacency list 
    start = clock(); 
    dijkstraList(graphList, 0); 
    end = clock(); 
    printf("Time taken for Adjacency List: %lf seconds\n", (double)(end - start) / 
CLOCKS_PER_SEC); 
    // Free memory (not shown for brevity) 
    free(graphMatrix); 
    free(graphList); 
    return 0; 
} 
