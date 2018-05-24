public class Main {

    public static void main(String[] args) {
        Graph graph = new Graph(4);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);


        if(graph.isCyclic())
            System.out.println("Graph contains cycle");
        else
            System.out.println("Graph doesn't "
                    + "contain cycle");
    }
}
