"""Undirected unweighted graph represented with adjacency lists."""
from collections import deque

class AdjacencyListGraph:
    def __init__(self, vertices):
        if vertices < 0: raise ValueError("Vertex count must be non-negative")
        self.adj = [[] for _ in range(vertices)]
    def _check(self, v):
        if not 0 <= v < len(self.adj): raise IndexError(f"Invalid vertex: {v}")
    def add_edge(self, u, v):
        self._check(u); self._check(v)
        if v not in self.adj[u]: self.adj[u].append(v)
        if u not in self.adj[v]: self.adj[v].append(u)
    def remove_edge(self, u, v):
        self._check(u); self._check(v)
        if v in self.adj[u]: self.adj[u].remove(v)
        if u in self.adj[v]: self.adj[v].remove(u)
    def display(self): return {i: neighbors[:] for i, neighbors in enumerate(self.adj)}
    def bfs(self, start):
        self._check(start); seen={start}; queue=deque([start]); order=[]
        while queue:
            u=queue.popleft(); order.append(u)
            for v in self.adj[u]:
                if v not in seen: seen.add(v); queue.append(v)
        return order
    def dfs(self, start):
        self._check(start); seen=set(); order=[]
        def visit(u):
            seen.add(u); order.append(u)
            for v in self.adj[u]:
                if v not in seen: visit(v)
        visit(start); return order
