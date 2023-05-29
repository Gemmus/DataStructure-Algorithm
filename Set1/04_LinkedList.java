// LinkedList
// - stores Nodes in 2 parts (data + address)
// Nodes are in non-consecutive memory locations
// - modes are linked using pointers

// 		    Singly Linked List: 
//       Node 	             Node  	         Node
// [data | address] -> [data | address] -> [data | address]

// 		    Doubly Linked List: 
// 	      Node                           Node
// [address | data | address ] -> [address | data | address ]

// Advantages: 
// - dynamic data structure (allocates needed memory while running)
// - insertion and deletion of Nodes are easy    O(1)
// - no/low memory waste

// Disadvantages: 
// - greater memory usage (additional pointer)
// - no random access of elements (no index[i])
// - accessing/searching elements is more time consuming   O(n)

// Uses: 
// - implement Stacks/Queues
// - GPS navigation
// - music playlist

import java.util.LinkedList;

public class Main{
	public static void main(String[] args){
		
		///////////////////////
		//   Using push():   //
		///////////////////////
		
		LinkedList<String> linkedList1 = new LinkedList<String>();
		
		linkedList1.push("A");
		linkedList1.push("B");
		linkedList1.push("C");
		linkedList1.push("D");
		linkedList1.push("F");
		System.out.println(linkedList1); // --> [F, D, C, B, A]
		
		linkedList1.pop();
		System.out.println(linkedList1); // --> [D, C, B, A] 
		
		////////////////////////
		//   Using offer():   //
		////////////////////////
		
		LinkedList<String> linkedList2 = new LinkedList<String>();
				
		linkedList2.offer("A");
		linkedList2.offer("B");
		linkedList2.offer("C");
		linkedList2.offer("D");
		linkedList2.offer("F");
		System.out.println(linkedList2); // --> [A, B, C, D, F]
		
		linkedList2.poll();
		System.out.println(linkedList2); // --> [B, C, D, F]
		
		///////////////////////////////////////////////////////
		// LinkedList allows insertion and deletion of notes //
		// unlike Arrays or ArrayList                        // 
		// but there is no random access to the LinkedList   //
		///////////////////////////////////////////////////////
		
		LinkedList<String> linkedList3 = new LinkedList<String>();
		
		linkedList3.offer("A");
		linkedList3.offer("B");
		linkedList3.offer("C");
		linkedList3.offer("D");
		linkedList3.offer("F");
		System.out.println(linkedList3);
		
		linkedList3.add(4, "E");
		System.out.println(linkedList3);
		linkedList3.remove("E");
		System.out.println(linkedList3);
		
		System.out.println(linkedList3.indexOf("F"));
		
		System.out.println(linkedList3.peekFirst());
		System.out.println(linkedList3.peekLast());
		
		linkedList3.addFirst("0");
		linkedList3.addLast("G");
		System.out.println(linkedList3);
		
		String first = linkedList3.removeFirst();
		System.out.println(first);
		String last  = linkedList3.removeLast();
		System.out.println(last);
		
		System.out.println(linkedList3);	
	}
}
