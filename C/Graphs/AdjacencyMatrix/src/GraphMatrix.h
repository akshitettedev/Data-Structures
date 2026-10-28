#pragma once
#define GRAPH_MAX_VERTICES 20

typedef struct {
    int vertexCount;
    int directed;
    int matrix[GRAPH_MAX_VERTICES][GRAPH_MAX_VERTICES];
} GraphMatrix;

int initializeGraphMatrix(GraphMatrix* graph, int vertexCount, int directed);
int addMatrixEdge(GraphMatrix* graph, int source, int destination, int weight);
void displayGraphMatrix(const GraphMatrix* graph);
void breadthFirstSearchMatrix(const GraphMatrix* graph, int startVertex);
void depthFirstSearchMatrix(const GraphMatrix* graph, int startVertex);
int primMinimumSpanningTree(const GraphMatrix* graph);
