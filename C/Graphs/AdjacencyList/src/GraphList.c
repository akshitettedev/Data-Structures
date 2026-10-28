#include <stdio.h>
#include <stdlib.h>
#include "GraphList.h"

static AdjNode* createAdjNode(int vertex, int weight) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    if (node == NULL) return NULL;
    node->vertex = vertex;
    node->weight = weight;
    node->next = NULL;
    return node;
}

int initializeGraphList(GraphList* graph, int vertexCount, int directed) {
    int i;
    if (graph == NULL || vertexCount < 1 || vertexCount > GRAPH_LIST_MAX_VERTICES) return 0;
    graph->vertexCount = vertexCount;
    graph->directed = directed != 0;
    for (i = 0; i < GRAPH_LIST_MAX_VERTICES; i++) graph->heads[i] = NULL;
    return 1;
}

static int addOneWayEdge(GraphList* graph, int source, int destination, int weight) {
    AdjNode* node = createAdjNode(destination, weight);
    AdjNode* tail;
    if (node == NULL) return 0;
    if (graph->heads[source] == NULL) graph->heads[source] = node;
    else {
        tail = graph->heads[source];
        while (tail->next != NULL) tail = tail->next;
        tail->next = node;
    }
    return 1;
}

int addListEdge(GraphList* graph, int source, int destination, int weight) {
    if (graph == NULL || source < 0 || destination < 0 ||
        source >= graph->vertexCount || destination >= graph->vertexCount || weight <= 0) return 0;
    if (!addOneWayEdge(graph, source, destination, weight)) return 0;
    if (!graph->directed && source != destination) {
        if (!addOneWayEdge(graph, destination, source, weight)) {
            /* Keep the graph consistent if the reverse allocation fails. */
            AdjNode* current = graph->heads[source];
            AdjNode* previous = NULL;
            while (current != NULL && !(current->vertex == destination && current->weight == weight)) {
                previous = current;
                current = current->next;
            }
            if (current != NULL) {
                if (previous == NULL) graph->heads[source] = current->next;
                else previous->next = current->next;
                free(current);
            }
            return 0;
        }
    }
    return 1;
}

void displayGraphList(const GraphList* graph) {
    int i;
    if (graph == NULL) return;
    printf("Adjacency list:\n");
    for (i = 0; i < graph->vertexCount; i++) {
        const AdjNode* current = graph->heads[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("(%d, w=%d) -> ", current->vertex, current->weight);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void breadthFirstSearchList(const GraphList* graph, int startVertex) {
    int visited[GRAPH_LIST_MAX_VERTICES] = {0};
    int queue[GRAPH_LIST_MAX_VERTICES];
    int front = 0, rear = 0;
    if (graph == NULL || startVertex < 0 || startVertex >= graph->vertexCount) {
        printf("Invalid BFS start vertex.\n"); return;
    }
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    while (front < rear) {
        int vertex = queue[front++];
        const AdjNode* current = graph->heads[vertex];
        printf("%d ", vertex);
        while (current != NULL) {
            if (!visited[current->vertex]) {
                visited[current->vertex] = 1;
                queue[rear++] = current->vertex;
            }
            current = current->next;
        }
    }
    printf("\n");
}

static void dfsListHelper(const GraphList* graph, int vertex, int visited[]) {
    const AdjNode* current;
    visited[vertex] = 1;
    printf("%d ", vertex);
    current = graph->heads[vertex];
    while (current != NULL) {
        if (!visited[current->vertex]) dfsListHelper(graph, current->vertex, visited);
        current = current->next;
    }
}

void depthFirstSearchList(const GraphList* graph, int startVertex) {
    int visited[GRAPH_LIST_MAX_VERTICES] = {0};
    if (graph == NULL || startVertex < 0 || startVertex >= graph->vertexCount) {
        printf("Invalid DFS start vertex.\n"); return;
    }
    dfsListHelper(graph, startVertex, visited);
    printf("\n");
}

void destroyGraphList(GraphList* graph) {
    int i;
    if (graph == NULL) return;
    for (i = 0; i < graph->vertexCount; i++) {
        AdjNode* current = graph->heads[i];
        while (current != NULL) {
            AdjNode* next = current->next;
            free(current);
            current = next;
        }
        graph->heads[i] = NULL;
    }
    graph->vertexCount = 0;
}
