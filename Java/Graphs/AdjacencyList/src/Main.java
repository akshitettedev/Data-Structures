public class Main {
    public static void main(String[] args) {
        AdjacencyListGraph graph = new AdjacencyListGraph(5);
        graph.addEdge(0,1); graph.addEdge(0,2); graph.addEdge(1,3); graph.addEdge(2,4);
        System.out.println("Adjacency list:"); graph.display();
        System.out.println("BFS from 0: " + graph.bfs(0));
        System.out.println("DFS from 0: " + graph.dfs(0));
    }
}
