#pragma once
#define GRAPH_LIST_MAX_VERTICES 20

typedef struct AdjNode {
    int vertex;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    int vertexCount;
    int directed;
    AdjNode* heads[GRAPH_LIST_MAX_VERTICES];
} GraphList;

int initializeGraphList(GraphList* graph, int vertexCount, int directed);
int addListEdge(GraphList* graph, int source, int destination, int weight);
void displayGraphList(const GraphList* graph);
void breadthFirstSearchList(const GraphList* graph, int startVertex);
void depthFirstSearchList(const GraphList* graph, int startVertex);
void destroyGraphList(GraphList* graph);
