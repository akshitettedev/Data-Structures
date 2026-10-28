from adjacency_matrix_graph import AdjacencyMatrixGraph

if __name__ == "__main__":
    graph = AdjacencyMatrixGraph(5)
    for u, v, w in [(0,1,2),(0,3,6),(1,2,3),(1,3,8),(1,4,5),(2,4,7),(3,4,9)]: graph.add_edge(u,v,w)
    print("Adjacency matrix:")
    for row in graph.display(): print(row)
    print("BFS:", graph.bfs(0))
    print("DFS:", graph.dfs(0))
    print("Prim MST weight:", graph.prim_mst_weight())
