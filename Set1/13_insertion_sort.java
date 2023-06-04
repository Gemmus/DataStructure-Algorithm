// Insertion Sort: O(n²)
// After comparing elements to the left, shifts elements to the right to make room to insert a value.

// Decent with small data sets. 
// Insufficient with large data sets.

// Less steps than Bubble Sort.
// Best case is O(n) compared to Selection Sort O(n²).

public class Main{
	
	public static void main(String[] args) {
		
		int array[] = {8, 7, 5, 1, 3, 9, 2, 4, 6};
		
		insertionSort(array);
		
		for(int i : array) {
			System.out.print(i + " ");
		}
	}
	
	private static void insertionSort(int[] array) {
		
		for(int i = 1; i < array.length; i++) {
			
			int temp = i;
			int j = i - 1;
			
			while(j >= 0 && array[j] > temp) {
				array[j + 1] = array[j];
				j--;
			}
			
			array[j+ 1] = temp;
		}
	}
}

