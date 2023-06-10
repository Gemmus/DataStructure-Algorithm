// Breadth First Search (BFS):
// A search algorithm for traversing a tree or graph data structure.
// This is done one "Level" at a time, rather than one "branch" at a time.

// Traverse a graph level by level.
// Utilizes a queue.
// Better if destination is on average close to start.
// Siblings are visited before children.

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
		graph.addEdge(1, 4); // B is connected to E
		graph.addEdge(2, 3); // C is connected to D
		graph.addEdge(2, 4); // C is connected to E
		graph.addEdge(4, 0); // E is connected to A
		graph.addEdge(4, 2); // E is connected to C
		
		graph.print();
		
		System.out.println();
		graph.breadthFirstSearch(0);
		
		System.out.println();
		graph.breadthFirstSearch(1);
		
		System.out.println();
		graph.breadthFirstSearch(2);
		
		System.out.println();
		graph.breadthFirstSearch(3);
		
		System.out.println();
		graph.breadthFirstSearch(4);
	}
}
