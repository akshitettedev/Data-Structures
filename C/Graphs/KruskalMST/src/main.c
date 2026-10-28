#include <stdio.h>
#include "Kruskal.h"

int main(void) {
    KruskalGraph graph;
    initializeKruskalGraph(&graph, 4);
    addKruskalEdge(&graph, 0, 1, 10);
    addKruskalEdge(&graph, 0, 2, 6);
    addKruskalEdge(&graph, 0, 3, 5);
    addKruskalEdge(&graph, 1, 3, 15);
    addKruskalEdge(&graph, 2, 3, 4);
    kruskalMinimumSpanningTree(&graph);
    return 0;
}
