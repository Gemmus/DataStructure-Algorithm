// Binary Search: O(log n)
// Search algorithm that finds the position of a target value within a sorted array.
// Half of the array is eliminated with each "step".

// Not efficient with smaller data sets.
// Efficient with large data sets.

import java.util.Arrays;

public class Main{
	
	public static void main(String args[]) {
		int array[] = new int[1000000];
		int target = 654286;
		
		for(int i = 0; i < array.length; i++) {
			array[i] = i;
		}
		
		//int index = Arrays.binarySearch(array, target);       // built-in function
		int index = binarySearch(array, target);                // own function
		
		if(index == -1) {
			System.out.println("Target not found.");
		}
		else {
			System.out.println("Target found at " + target + ".");
		}
	}
		
	private static int binarySearch(int[] array, int target) {
		
		int low = 0;
		int high = array.length - 1;
		
		while(low <= high) {
			int middle = low + (high - low) / 2;
			int value = array[middle];
			
			System.out.println("middle: " + value);
			
			if(value < target) low = middle + 1;
			else if(value > target) high = middle - 1;
			else return middle; // target found		
		}
		return -1; // target not found
	}
}
