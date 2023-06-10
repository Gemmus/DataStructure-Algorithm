// Binary Search Tree:
// A tree data structure, where each node is greater than it's left child, but less than it's right.

// Benefit: Easy to locate a node, when they are in this order.
// Time complexity: best case O(log n)
//                  worst case O(n)
// Space complexity: O(n)

public class Main{
	
	public static void main(String[] args) {
		
		BinarySearchTree tree = new BinarySearchTree();
		
		tree.insert(new Node(5));
		tree.insert(new Node(1));
		tree.insert(new Node(9));
		tree.insert(new Node(2));
		tree.insert(new Node(7));
		tree.insert(new Node(3));
		tree.insert(new Node(6));
		tree.insert(new Node(4));
		tree.insert(new Node(8));
		
		tree.display();
		
		// Search: returns true or false
		System.out.println();
		System.out.println(tree.search(0));
		System.out.println(tree.search(1));
		
		// Remove: removes or warns if not found
		System.out.println();
		tree.remove(0);
		
		System.out.println();
		tree.remove(6);
		tree.display();
	}
}
