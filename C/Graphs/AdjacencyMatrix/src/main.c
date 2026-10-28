#include <stdio.h>
#include "GraphMatrix.h"

int main(void) {
    GraphMatrix graph;
    if (!initializeGraphMatrix(&graph, 5, 0)) return 1; /* 0 means undirected */

    addMatrixEdge(&graph, 0, 1, 2);
    addMatrixEdge(&graph, 0, 3, 6);
    addMatrixEdge(&graph, 1, 2, 3);
    addMatrixEdge(&graph, 1, 3, 8);
    addMatrixEdge(&graph, 1, 4, 5);
    addMatrixEdge(&graph, 2, 4, 7);
    addMatrixEdge(&graph, 3, 4, 9);

    displayGraphMatrix(&graph);
    printf("BFS from vertex 0: "); breadthFirstSearchMatrix(&graph, 0);
    printf("DFS from vertex 0: "); depthFirstSearchMatrix(&graph, 0);
    primMinimumSpanningTree(&graph);
    return 0;
}
