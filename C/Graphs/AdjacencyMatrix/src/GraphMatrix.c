#include <stdio.h>
#include <limits.h>
#include "GraphMatrix.h"

int initializeGraphMatrix(GraphMatrix* graph, int vertexCount, int directed) {
    int i, j;
    if (graph == NULL || vertexCount < 1 || vertexCount > GRAPH_MAX_VERTICES) return 0;
    graph->vertexCount = vertexCount;
    graph->directed = directed != 0;
    for (i = 0; i < GRAPH_MAX_VERTICES; i++)
        for (j = 0; j < GRAPH_MAX_VERTICES; j++) graph->matrix[i][j] = 0;
    return 1;
}

int addMatrixEdge(GraphMatrix* graph, int source, int destination, int weight) {
    if (graph == NULL || source < 0 || destination < 0 ||
        source >= graph->vertexCount || destination >= graph->vertexCount || weight <= 0) return 0;
    graph->matrix[source][destination] = weight;
    if (!graph->directed) graph->matrix[destination][source] = weight;
    return 1;
}

void displayGraphMatrix(const GraphMatrix* graph) {
    int i, j;
    if (graph == NULL) return;
    printf("\nAdjacency matrix (0 means no edge):\n    ");
    for (i = 0; i < graph->vertexCount; i++) printf("%4d", i);
    printf("\n");
    for (i = 0; i < graph->vertexCount; i++) {
        printf("%4d", i);
        for (j = 0; j < graph->vertexCount; j++) printf("%4d", graph->matrix[i][j]);
        printf("\n");
    }
}

void breadthFirstSearchMatrix(const GraphMatrix* graph, int startVertex) {
    int visited[GRAPH_MAX_VERTICES] = {0};
    int queue[GRAPH_MAX_VERTICES];
    int front = 0, rear = 0;
    int i;
    if (graph == NULL || startVertex < 0 || startVertex >= graph->vertexCount) {
        printf("Invalid BFS start vertex.\n"); return;
    }
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (i = 0; i < graph->vertexCount; i++) {
            if (graph->matrix[current][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

static void dfsMatrixHelper(const GraphMatrix* graph, int vertex, int visited[]) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (i = 0; i < graph->vertexCount; i++) {
        if (graph->matrix[vertex][i] != 0 && !visited[i])
            dfsMatrixHelper(graph, i, visited);
    }
}

void depthFirstSearchMatrix(const GraphMatrix* graph, int startVertex) {
    int visited[GRAPH_MAX_VERTICES] = {0};
    if (graph == NULL || startVertex < 0 || startVertex >= graph->vertexCount) {
        printf("Invalid DFS start vertex.\n"); return;
    }
    dfsMatrixHelper(graph, startVertex, visited);
    printf("\n");
}

int primMinimumSpanningTree(const GraphMatrix* graph) {
    int parent[GRAPH_MAX_VERTICES];
    int key[GRAPH_MAX_VERTICES];
    int inTree[GRAPH_MAX_VERTICES] = {0};
    int i, step, totalWeight = 0;
    if (graph == NULL || graph->directed || graph->vertexCount < 1) {
        printf("Prim's algorithm requires an initialized, undirected graph.\n");
        return 0;
    }
    for (i = 0; i < graph->vertexCount; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[0] = 0;

    for (step = 0; step < graph->vertexCount; step++) {
        int minimum = INT_MAX;
        int vertex = -1;
        for (i = 0; i < graph->vertexCount; i++) {
            if (!inTree[i] && key[i] < minimum) {
                minimum = key[i];
                vertex = i;
            }
        }
        if (vertex == -1) {
            printf("Graph is disconnected; no spanning tree exists.\n");
            return 0;
        }
        inTree[vertex] = 1;
        for (i = 0; i < graph->vertexCount; i++) {
            int weight = graph->matrix[vertex][i];
            if (weight > 0 && !inTree[i] && weight < key[i]) {
                key[i] = weight;
                parent[i] = vertex;
            }
        }
    }

    printf("\nPrim minimum spanning tree edges:\n");
    for (i = 1; i < graph->vertexCount; i++) {
        printf("%d -- %d (weight %d)\n", parent[i], i, graph->matrix[parent[i]][i]);
        totalWeight += graph->matrix[parent[i]][i];
    }
    printf("Total MST weight: %d\n", totalWeight);
    return 1;
}
