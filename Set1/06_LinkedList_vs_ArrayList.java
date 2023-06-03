// LinkedList vs ArrayList:

// - get(0): ArrayList faster (because LinkedList is doubly, it can start from the head or from the tail)
// - get(500000): ArrayList much faster
// - get(999999): ArrayList faster (because LinkedList is doubly, it can start from the head or from the tail)

// - remove(0): LinkedList much faster (because ArrayList needs to shift all elements to the left after deletion)
// - remove(500000): ArrayList faster (less element to shift)
// - remove(999999): ArrayList slightly faster

// Conclusion:
// - in most cases the ArrayList is preferable, as it is more flexible for most applications
// - however, if a lot of insertion and deletion are required, LinkedList is the better choice
		
import java.util.ArrayList;
import java.util.LinkedList;

public class Main{
	
	public static void main(String[] args) {
		
		LinkedList<Integer> linkedList = new LinkedList<Integer>();
		ArrayList<Integer> arrayList = new ArrayList<Integer>();
		
		long startTime;
		long endTime;
		long elapsedTime;
		
		for(int i = 0; i < 1000000; i++) {
			linkedList.add(i);
			arrayList.add(i);
		}

		//**************************** LinkedList *****************************
		
		startTime = System.nanoTime();
		
		//linkedList.get(0);
		//linkedList.get(500000);
		//linkedList.get(999999);
		
		//linkedList.remove(0);
		//linkedList.remove(500000);
		linkedList.remove(999999);
		
		endTime = System.nanoTime();
		
		elapsedTime = endTime - startTime;
		System.out.println("LinkedList:\t" + elapsedTime + " ns.");
		
		//****************************  ArrayList *****************************

		startTime = System.nanoTime();
		
		//arrayList.get(0);
		//arrayList.get(500000);
		//arrayList.get(999999);
		
		//arrayList.remove(0);
		//arrayList.remove(500000);
		arrayList.remove(999999);
		
		endTime = System.nanoTime();
		
		elapsedTime = endTime - startTime;
		System.out.println("ArrayList:\t" + elapsedTime + " ns.");
	}
}
