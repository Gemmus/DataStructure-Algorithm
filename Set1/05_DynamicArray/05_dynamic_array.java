// Advantages:
// - random access of elements	O(1)
// - good locality of reference and data cache utilization
// - easy to insert/delete at the end

// Disadvantages:
// - consumes more memory
// - shifting elements is time consuming	O(n)
// - expanding/shrinking the array is time consuming	O(n)

public class Main{
	
	public static void main(String[] args) {
		
		DynamicArray dynamicArray = new DynamicArray(5); // can be set with an integer, standard is 10

		dynamicArray.add("A");
		dynamicArray.add("B");
		dynamicArray.add("C");
		
		//dynamicArray.insert(0, "X");
		//dynamicArray.delete("A");
		//System.out.println(dynamicArray.search("C"));
		
		//////////////////////////////////////////////////////////////////////////
		// Once the capacity if 5 is exceeded, it will increase the capacity:	  //
		// [A, B, C, D, E, F, null, null, null, null]					              		//
		//////////////////////////////////////////////////////////////////////////
				
		dynamicArray.add("D");
		dynamicArray.add("E");
		dynamicArray.add("F");
		
		System.out.println(dynamicArray);
		System.out.println("Size: " + dynamicArray.size + ".");
		System.out.println("Capacity: " + dynamicArray.capacity + ".");
		System.out.println("Empty: " + dynamicArray.isEmpty() +".");
		
		//////////////////////////////////////////////////////////////////////////////////////
		// Once the less than 1/3 of the capacity is used, it will decrease the capacity: 	//
		// [A, B, C, null, null]			      									                          		//
		//////////////////////////////////////////////////////////////////////////////////////
	
		dynamicArray.delete("F"); 
		dynamicArray.delete("E");
		dynamicArray.delete("D");
		
		System.out.println("\n" + dynamicArray);
		System.out.println("Size: " + dynamicArray.size + ".");
		System.out.println("Capacity: " + dynamicArray.capacity + ".");
		System.out.println("Empty: " + dynamicArray.isEmpty() +".");
	}
}
