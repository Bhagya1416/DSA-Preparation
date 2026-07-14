#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Queue structure
struct Queue {
    int* items;
    int front;
    int rear;
    int size;
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Adjacency list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Create queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->items = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, int value) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// BFS traversal
void bfs(struct Graph* graph, int startVertex) {
    // Reset visited array
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;

    struct Queue* q = createQueue(graph->numVertices);

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");

    free(q->items);
    free(q);
}

// Main program
int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add edge\n");
        printf("2. Print graph\n");
        printf("3. BFS traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int src, dest;
                printf("Enter source and destination (0 to %d): ", vertices - 1);
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                    addEdge(graph, src, dest);
                } else {
                    printf("Invalid vertices!\n");
                }
                break;
            }

            case 2:
                printGraph(graph);
                break;

            case 3: {
                int start;
                printf("Enter starting vertex (0 to %d): ", vertices - 1);
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    bfs(graph, start);
                } else {
                    printf("Invalid starting vertex!\n");
                }
                break;
            }

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}


 
