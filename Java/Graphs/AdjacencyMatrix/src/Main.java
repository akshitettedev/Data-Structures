public class Main {
    public static void main(String[] args) {
        AdjacencyMatrixGraph graph = new AdjacencyMatrixGraph(5);
        graph.addEdge(0,1,2); graph.addEdge(0,3,6); graph.addEdge(1,2,3); graph.addEdge(1,3,8); graph.addEdge(1,4,5); graph.addEdge(2,4,7); graph.addEdge(3,4,9);
        System.out.println("Adjacency matrix:"); graph.display();
        System.out.println("BFS: " + graph.bfs(0));
        System.out.println("DFS: " + graph.dfs(0));
        System.out.println("Prim MST weight: " + graph.primMSTWeight());
    }
}
