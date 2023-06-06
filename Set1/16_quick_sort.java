// Quick Sort: 
// Moves smaller elements to left of a pivot.
// Recursively divide array in 2 partitions.

// Run-time Complexity: 
// - best case: O(n log n )
// - average case: O(n log n)
// - worst case O(n²) if already sorted

// Space complexity = O(log n) due recursion

public class Main{
	
	public static void main(String[] args) {

		int[] array = {8, 6, 3, 9, 4, 5, 1, 7, 2};
		
		quickSort(array, 0, array.length - 1);
		
		for(int i : array) {
			System.out.print(i + " ");
		}
	}
	
	private static void quickSort(int[] array, int start, int end) {
		
		// Base Case:
		if(end <= start) return;
		
		int pivot = partition(array, start, end);
		quickSort(array, start, pivot -1);
		quickSort(array, pivot + 1, end);
	}
	
	private static int partition(int[] array, int start, int end) {
		
		int pivot = array[end];
		int i = start -1;
		
		for(int j = start; j <= end - 1; j++) {
			if(array[j] < pivot) {
				i++;
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		
		i++;
		int temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		
		return i;
	}
}
