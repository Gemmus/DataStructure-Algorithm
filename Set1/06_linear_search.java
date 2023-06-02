// Linear Search: O(n)

// Iterate through a collection one element at a time

// Disadvantages: 
// - slow for large data sets

// Advantages:
// - fast for searches of small to medium data sets
// - does not need to be sorted
// - useful for data structures that do not have random access (LinkedList)

public class Main{
	
	public static void main(String args[]) {
		
		
		int[] array = {9, 1, 5, 6, 3, 8, 4, 7, 2};
		
		int index = linearSearch(array, 8);
		
		if(index != -1) {
			System.out.println("Element found at index: " + index + ".");
		}
		else {
			System.out.println("Element not found.");
		}
	}
	
	private static int linearSearch(int[] array, int value) {
		
		for(int i = 0; i < array.length; i++) {
			if(array[i] == value) {
				return i;
			}
		}
		return -1;
	}
}
