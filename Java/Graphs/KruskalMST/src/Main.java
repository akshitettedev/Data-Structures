public class Main {
    public static void main(String[] args) {
        KruskalMST graph = new KruskalMST(4);
        graph.addEdge(0,1,10); graph.addEdge(0,2,6); graph.addEdge(0,3,5); graph.addEdge(1,3,15); graph.addEdge(2,3,4);
        System.out.println("Edges in MST:");
        for (KruskalMST.Edge edge : graph.minimumSpanningTree()) System.out.println(edge);
        System.out.println("Total weight: " + graph.totalWeight());
    }
}
