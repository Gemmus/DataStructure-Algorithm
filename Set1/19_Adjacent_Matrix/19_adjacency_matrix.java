// Adjacency Matrix:
// A 2D array to store 1's/0's to represent edges. (or can use booleans)
//                        # of rows =        # of unique nodes
//                        # of columns =     # of unique nodes

// Runtime complexity to check an Edge: O(1).
// Space complexity: O(v²).

public class Main{
	
	public static void main(String[] args) {
		
		Graph graph = new Graph(5);
		
		graph.addNode(new Node('A')); // index = 0
		graph.addNode(new Node('B')); // index = 1
		graph.addNode(new Node('C')); // index = 2
		graph.addNode(new Node('D')); // index = 3
		graph.addNode(new Node('E')); // index = 4
		
		graph.addEdge(0, 1); // A is connected to B
		graph.addEdge(1, 2); // B is connected to C
		graph.addEdge(2, 3); // C is connected to D
		graph.addEdge(2, 4); // C is connected to E
		graph.addEdge(4, 0); // E is connected to A
		graph.addEdge(4, 2); // E is connected to C
		
		graph.print();
		
		System.out.println();
		System.out.println(graph.checkEdge(0, 1)); // Edge AB?
		System.out.println(graph.checkEdge(3, 2)); // Edge DC?
	}
}
