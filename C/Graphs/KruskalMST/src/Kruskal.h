#pragma once
#define KRUSKAL_MAX_VERTICES 20
#define KRUSKAL_MAX_EDGES 100

typedef struct {
    int source;
    int destination;
    int weight;
} GraphEdge;

typedef struct {
    int vertexCount;
    int edgeCount;
    GraphEdge edges[KRUSKAL_MAX_EDGES];
} KruskalGraph;

int initializeKruskalGraph(KruskalGraph* graph, int vertexCount);
int addKruskalEdge(KruskalGraph* graph, int source, int destination, int weight);
int kruskalMinimumSpanningTree(const KruskalGraph* graph);
