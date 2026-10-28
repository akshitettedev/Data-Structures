from kruskal_mst import KruskalMST

if __name__ == "__main__":
    graph = KruskalMST(4)
    for u,v,w in [(0,1,10),(0,2,6),(0,3,5),(1,3,15),(2,3,4)]:graph.add_edge(u,v,w)
    print("Edges in MST:")
    for edge in graph.minimum_spanning_tree():print(edge)
    print("Total weight:",graph.total_weight())
