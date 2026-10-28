"""Kruskal minimum spanning tree using disjoint-set union (union-find)."""
class KruskalMST:
    def __init__(self, vertices):
        if vertices < 0: raise ValueError("Vertex count must be non-negative")
        self.vertices=vertices;self.edges=[]
    def add_edge(self,u,v,weight):
        if not (0<=u<self.vertices and 0<=v<self.vertices) or u==v: raise IndexError("Invalid edge endpoints")
        self.edges.append((weight,u,v))
    def minimum_spanning_tree(self):
        parent=list(range(self.vertices));rank=[0]*self.vertices
        def find(x):
            while parent[x]!=x:parent[x]=parent[parent[x]];x=parent[x]
            return x
        def union(a,b):
            a,b=find(a),find(b)
            if a==b:return False
            if rank[a]<rank[b]:parent[a]=b
            elif rank[a]>rank[b]:parent[b]=a
            else:parent[b]=a;rank[a]+=1
            return True
        result=[]
        for weight,u,v in sorted(self.edges):
            if union(u,v):
                result.append((u,v,weight))
                if len(result)==max(0,self.vertices-1):break
        if self.vertices>0 and len(result)!=self.vertices-1:raise ValueError("Graph is disconnected; no spanning tree exists")
        return result
    def total_weight(self): return sum(weight for _,_,weight in self.minimum_spanning_tree())
