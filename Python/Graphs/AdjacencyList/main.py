from adjacency_list_graph import AdjacencyListGraph

if __name__ == "__main__":
    graph = AdjacencyListGraph(5)
    for u, v in [(0, 1), (0, 2), (1, 3), (2, 4)]: graph.add_edge(u, v)
    print("Adjacency list:", graph.display())
    print("BFS from 0:", graph.bfs(0))
    print("DFS from 0:", graph.dfs(0))
