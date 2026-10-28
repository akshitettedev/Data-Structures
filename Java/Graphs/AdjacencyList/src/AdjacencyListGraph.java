import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

/** Undirected, unweighted graph represented by adjacency lists. */
public class AdjacencyListGraph {
    private final List<List<Integer>> adj;
    public AdjacencyListGraph(int vertices) { if (vertices < 0) throw new IllegalArgumentException(); adj = new ArrayList<>(); for (int i=0;i<vertices;i++) adj.add(new ArrayList<>()); }
    private void check(int v) { if (v < 0 || v >= adj.size()) throw new IndexOutOfBoundsException("Vertex: " + v); }
    public int vertices() { return adj.size(); }
    public void addEdge(int u, int v) { check(u); check(v); if (!adj.get(u).contains(v)) adj.get(u).add(v); if (!adj.get(v).contains(u)) adj.get(v).add(u); }
    public void removeEdge(int u, int v) { check(u); check(v); adj.get(u).remove(Integer.valueOf(v)); adj.get(v).remove(Integer.valueOf(u)); }
    public void display() { for (int i=0;i<adj.size();i++) System.out.println(i + " -> " + adj.get(i)); }
    public List<Integer> bfs(int start) { check(start); boolean[] seen=new boolean[vertices()]; Queue<Integer> q=new ArrayDeque<>(); List<Integer> order=new ArrayList<>(); seen[start]=true; q.add(start); while(!q.isEmpty()){int u=q.remove();order.add(u);for(int v:adj.get(u))if(!seen[v]){seen[v]=true;q.add(v);}} return order; }
    public List<Integer> dfs(int start) { check(start); boolean[] seen=new boolean[vertices()]; List<Integer> order=new ArrayList<>(); dfs(start,seen,order); return order; }
    private void dfs(int u, boolean[] seen, List<Integer> order) { seen[u]=true; order.add(u); for(int v:adj.get(u)) if(!seen[v]) dfs(v,seen,order); }
}
