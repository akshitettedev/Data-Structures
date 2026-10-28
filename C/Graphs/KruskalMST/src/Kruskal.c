#include <stdio.h>
#include <stdlib.h>
#include "Kruskal.h"

static int compareEdges(const void* first, const void* second) {
    const GraphEdge* a = (const GraphEdge*)first;
    const GraphEdge* b = (const GraphEdge*)second;
    if (a->weight < b->weight) return -1;
    if (a->weight > b->weight) return 1;
    return 0;
}

static int findRoot(int parent[], int vertex) {
    if (parent[vertex] != vertex) parent[vertex] = findRoot(parent, parent[vertex]);
    return parent[vertex];
}

static int unionSets(int parent[], int rank[], int first, int second) {
    int rootFirst = findRoot(parent, first);
    int rootSecond = findRoot(parent, second);
    if (rootFirst == rootSecond) return 0;
    if (rank[rootFirst] < rank[rootSecond]) parent[rootFirst] = rootSecond;
    else if (rank[rootFirst] > rank[rootSecond]) parent[rootSecond] = rootFirst;
    else { parent[rootSecond] = rootFirst; rank[rootFirst]++; }
    return 1;
}

int initializeKruskalGraph(KruskalGraph* graph, int vertexCount) {
    if (graph == NULL || vertexCount < 1 || vertexCount > KRUSKAL_MAX_VERTICES) return 0;
    graph->vertexCount = vertexCount;
    graph->edgeCount = 0;
    return 1;
}

int addKruskalEdge(KruskalGraph* graph, int source, int destination, int weight) {
    GraphEdge* edge;
    if (graph == NULL || source < 0 || destination < 0 || source >= graph->vertexCount ||
        destination >= graph->vertexCount || source == destination || graph->edgeCount >= KRUSKAL_MAX_EDGES) return 0;
    edge = &graph->edges[graph->edgeCount++];
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;
    return 1;
}

int kruskalMinimumSpanningTree(const KruskalGraph* graph) {
    GraphEdge edges[KRUSKAL_MAX_EDGES];
    int parent[KRUSKAL_MAX_VERTICES];
    int rank[KRUSKAL_MAX_VERTICES] = {0};
    int i, selected = 0, totalWeight = 0;
    if (graph == NULL || graph->vertexCount < 1) return 0;
    for (i = 0; i < graph->vertexCount; i++) parent[i] = i;
    for (i = 0; i < graph->edgeCount; i++) edges[i] = graph->edges[i];
    qsort(edges, (size_t)graph->edgeCount, sizeof(GraphEdge), compareEdges);

    printf("Kruskal minimum spanning tree edges:\n");
    for (i = 0; i < graph->edgeCount && selected < graph->vertexCount - 1; i++) {
        GraphEdge edge = edges[i];
        if (unionSets(parent, rank, edge.source, edge.destination)) {
            printf("%d -- %d (weight %d)\n", edge.source, edge.destination, edge.weight);
            totalWeight += edge.weight;
            selected++;
        }
    }
    if (selected != graph->vertexCount - 1) {
        printf("Graph is disconnected; no spanning tree exists.\n");
        return 0;
    }
    printf("Total MST weight: %d\n", totalWeight);
    return 1;
}
