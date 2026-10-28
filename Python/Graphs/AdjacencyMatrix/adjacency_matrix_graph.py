"""Undirected weighted graph; weight 0 means no edge, edge weights must be positive."""
from collections import deque

class AdjacencyMatrixGraph:
    def __init__(self, vertices):
        if vertices < 0: raise ValueError("Vertex count must be non-negative")
        self.matrix=[[0]*vertices for _ in range(vertices)]
    def _check(self,v):
        if not 0 <= v < len(self.matrix): raise IndexError(f"Invalid vertex: {v}")
    def add_edge(self,u,v,weight):
        self._check(u); self._check(v)
        if u==v or weight<=0: raise ValueError("Use distinct vertices and a positive weight")
        self.matrix[u][v]=self.matrix[v][u]=weight
    def remove_edge(self,u,v):
        self._check(u);self._check(v);self.matrix[u][v]=self.matrix[v][u]=0
    def display(self): return [row[:] for row in self.matrix]
    def bfs(self,start):
        self._check(start); seen={start}; q=deque([start]); order=[]
        while q:
            u=q.popleft();order.append(u)
            for v,w in enumerate(self.matrix[u]):
                if w>0 and v not in seen:seen.add(v);q.append(v)
        return order
    def dfs(self,start):
        self._check(start);seen=set();order=[]
        def visit(u):
            seen.add(u);order.append(u)
            for v,w in enumerate(self.matrix[u]):
                if w>0 and v not in seen:visit(v)
        visit(start);return order
    def prim_mst_weight(self):
        n=len(self.matrix)
        if n==0:return 0
        key=[float("inf")]*n;in_mst=[False]*n;key[0]=0;total=0
        for _ in range(n):
            u=min((i for i in range(n) if not in_mst[i]), key=lambda i:key[i], default=None)
            if u is None or key[u]==float("inf"):return None
            in_mst[u]=True;total+=key[u]
            for v,w in enumerate(self.matrix[u]):
                if w>0 and not in_mst[v] and w<key[v]:key[v]=w
        return total
