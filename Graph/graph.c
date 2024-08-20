#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTICES 100

// Global variables
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;
int vertices;

// Function prototypes
void initializeGraph();
void addEdge(int u, int v);
void displayGraph();
void DFS(int vertex);
void BFS(int vertex);
void enqueue(int vertex);
int dequeue();

// Initialize graph
void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

// Add edge to the graph
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}

// Display the adjacency matrix representation of the graph
void displayGraph() {
    printf("Adjacency Matrix Representation of the Graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Depth-First Search (DFS) traversal
void DFS(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// Breadth-First Search (BFS) traversal
void BFS(int vertex) {
    visited[vertex] = true;
    enqueue(vertex);
    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

// Enqueue operation
void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

// Dequeue operation
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return item;
}

int main() {
    int choice, startVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    initializeGraph();

    do {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. DFS Traversal\n");
        printf("4. BFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the vertices (u v) of the edge: ");
                int u, v;
                scanf("%d %d", &u, &v);
                if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
                    printf("Invalid vertices!\n");
                    break;
                }
                addEdge(u, v);
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                printf("Enter the starting vertex for DFS traversal: ");
                scanf("%d", &startVertex);
                if (startVertex < 0 || startVertex >= vertices) {
                    printf("Invalid starting vertex!\n");
                    break;
                }
                printf("DFS Traversal: ");
                DFS(startVertex);
                printf("\n");
                // Reset visited array
                for (int i = 0; i < vertices; i++) {
                    visited[i] = false;
                }
                break;
            case 4:
                printf("Enter the starting vertex for BFS traversal: ");
                scanf("%d", &startVertex);
                if (startVertex < 0 || startVertex >= vertices) {
                    printf("Invalid starting vertex!\n");
                    break;
                }
                printf("BFS Traversal: ");
                BFS(startVertex);
                printf("\n");
                // Reset visited array
                for (int i = 0; i < vertices; i++) {
                    visited[i] = false;
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}