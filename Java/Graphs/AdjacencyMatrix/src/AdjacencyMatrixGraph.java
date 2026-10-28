import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;

/** Undirected weighted graph. A weight of 0 means there is no edge. */
public class AdjacencyMatrixGraph {
    private final int[][] matrix;
    public AdjacencyMatrixGraph(int vertices) { if (vertices < 0) throw new IllegalArgumentException(); matrix=new int[vertices][vertices]; }
    private void check(int v){if(v<0||v>=matrix.length)throw new IndexOutOfBoundsException("Vertex: "+v);}
    public int vertices(){return matrix.length;}
    public void addEdge(int u,int v,int weight){check(u);check(v);if(u==v||weight<=0)throw new IllegalArgumentException("Use distinct vertices and a positive weight");matrix[u][v]=weight;matrix[v][u]=weight;}
    public void removeEdge(int u,int v){check(u);check(v);matrix[u][v]=matrix[v][u]=0;}
    public void display(){for(int[] row:matrix)System.out.println(Arrays.toString(row));}
    public List<Integer> bfs(int start){check(start);boolean[] seen=new boolean[vertices()];Queue<Integer> q=new ArrayDeque<>();List<Integer> order=new ArrayList<>();seen[start]=true;q.add(start);while(!q.isEmpty()){int u=q.remove();order.add(u);for(int v=0;v<vertices();v++)if(matrix[u][v]>0&&!seen[v]){seen[v]=true;q.add(v);}}return order;}
    public List<Integer> dfs(int start){check(start);boolean[] seen=new boolean[vertices()];List<Integer> order=new ArrayList<>();dfs(start,seen,order);return order;}
    private void dfs(int u,boolean[] seen,List<Integer> order){seen[u]=true;order.add(u);for(int v=0;v<vertices();v++)if(matrix[u][v]>0&&!seen[v])dfs(v,seen,order);}
    /** Prim's MST; returns -1 when the graph is disconnected. */
    public int primMSTWeight(){int n=vertices();if(n==0)return 0;int[] key=new int[n];boolean[] in=new boolean[n];Arrays.fill(key,Integer.MAX_VALUE);key[0]=0;int total=0;for(int count=0;count<n;count++){int u=-1;for(int v=0;v<n;v++)if(!in[v]&&(u==-1||key[v]<key[u]))u=v;if(u==-1||key[u]==Integer.MAX_VALUE)return -1;in[u]=true;total+=key[u];for(int v=0;v<n;v++)if(matrix[u][v]>0&&!in[v]&&matrix[u][v]<key[v])key[v]=matrix[u][v];}return total;}
}
