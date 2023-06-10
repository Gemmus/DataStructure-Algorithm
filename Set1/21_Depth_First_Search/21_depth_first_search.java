// Depth First Search (DFS):
// A search algorithm for traversing a tree or graph data structure.

// 1. Pick a route.
// 2. Keep going until you reach a dead end, or a previously visited node.
// 3. Backtrack to last node that has unvisited adjacent neighbors.

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
		graph.depthFirstSearch(0);
		
		System.out.println();
		graph.depthFirstSearch(1);
		
		System.out.println();
		graph.depthFirstSearch(2);
		
		System.out.println();
		graph.depthFirstSearch(3);
		
		System.out.println();
		graph.depthFirstSearch(4);
	}
}
