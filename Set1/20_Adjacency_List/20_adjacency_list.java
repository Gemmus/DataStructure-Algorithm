// Adjacency List:
// An array/ArrayList of LinkedLists.
// Each LinkedList has a unique node at the head.
// All adjacent neighbors tom that node arte added to that node's LinkedList.

// Runtime complexity to check an Edge: O(V).
// Space complexity: O(V + E).

public class Main{
	
	public static void main(String[] args) {
		
		Graph graph = new Graph();
		
		graph.addNode(new Node('A')); // index = 0
		graph.addNode(new Node('B')); // index = 1
		graph.addNode(new Node('C')); // index = 2
		graph.addNode(new Node('D')); // index = 3
		graph.addNode(new Node('E')); // index = 4
		
		graph.addEdge(0, 1); // A is connected to B
		graph.addEdge(1, 2); // B is connected to C
		graph.addEdge(1, 4); // B is connected to E
		graph.addEdge(2, 3); // C is connected to D
		graph.addEdge(2, 4); // C is connected to E
		graph.addEdge(4, 0); // E is connected to A
		graph.addEdge(4, 2); // E is connected to C
		
		graph.print();
	}
}
