import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/** Kruskal minimum-spanning-tree algorithm with union-find. */
public class KruskalMST {
    public static class Edge { public final int src,dest,weight; public Edge(int src,int dest,int weight){this.src=src;this.dest=dest;this.weight=weight;} @Override public String toString(){return src+" - "+dest+" ("+weight+")";} }
    private final int vertices; private final List<Edge> edges=new ArrayList<>();
    public KruskalMST(int vertices){if(vertices<0)throw new IllegalArgumentException();this.vertices=vertices;}
    public void addEdge(int u,int v,int weight){if(u<0||u>=vertices||v<0||v>=vertices||u==v)throw new IndexOutOfBoundsException("Invalid endpoint");edges.add(new Edge(u,v,weight));}
    private static class DSU { int[] p,rank; DSU(int n){p=new int[n];rank=new int[n];for(int i=0;i<n;i++)p[i]=i;} int find(int x){if(p[x]!=x)p[x]=find(p[x]);return p[x];} boolean union(int a,int b){a=find(a);b=find(b);if(a==b)return false;if(rank[a]<rank[b])p[a]=b;else if(rank[a]>rank[b])p[b]=a;else{p[b]=a;rank[a]++;}return true;} }
    public List<Edge> minimumSpanningTree(){List<Edge> sorted=new ArrayList<>(edges);sorted.sort(Comparator.comparingInt(e->e.weight));List<Edge> result=new ArrayList<>();DSU dsu=new DSU(vertices);for(Edge e:sorted){if(dsu.union(e.src,e.dest)){result.add(e);if(result.size()==Math.max(0,vertices-1))break;}}if(vertices>0&&result.size()!=vertices-1)throw new IllegalStateException("Graph is disconnected; no spanning tree exists");return result;}
    public int totalWeight(){int total=0;for(Edge e:minimumSpanningTree())total+=e.weight;return total;}
}
