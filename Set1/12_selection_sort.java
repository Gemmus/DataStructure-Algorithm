// Selection Sort: O(n²)
// Search through an array and keep track of the minimum value during each iteration.
// At the end of each iteration, we swap variables.

// Suitable for small data sets.
// Inefficient with large data sets.

public class Main{
	
	public static void main(String[] args) {
		
		int array[] = {8, 7, 5, 1, 3, 9, 2, 4, 6};
		
		selectionSort(array);
		
		for(int i : array) {
			System.out.print(i + " ");
		}
	}
	
	private static void selectionSort(int[] array) {
		
		for(int i = 0; i < array.length - 1; i++) {
			
			int min = i;
			
			for(int j = i + 1; j < array.length; j++) {
				if(array[min] > array[j]) { 			                		// >: ascending order; <: descending order
					min = j;
				}
			}
			
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

