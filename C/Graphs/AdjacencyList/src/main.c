#include <stdio.h>
#include "GraphList.h"

int main(void) {
    GraphList graph;
    if (!initializeGraphList(&graph, 5, 0)) return 1;
    addListEdge(&graph, 0, 1, 1);
    addListEdge(&graph, 0, 2, 1);
    addListEdge(&graph, 1, 3, 1);
    addListEdge(&graph, 2, 3, 1);
    addListEdge(&graph, 3, 4, 1);

    displayGraphList(&graph);
    printf("BFS from vertex 0: "); breadthFirstSearchList(&graph, 0);
    printf("DFS from vertex 0: "); depthFirstSearchList(&graph, 0);
    destroyGraphList(&graph);
    return 0;
}
