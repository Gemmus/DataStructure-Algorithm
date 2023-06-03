// Bubble Sort: O(n²) = quadratic
// Pairs of adjacent elements are compared, and the elements are swapped if they are not in order.

// Okay-ish for smaller data sets.
// Insufficient with large data sets

public class Main{
	
	public static void main(String[] args) {
		
		int array[] = {9, 1, 5, 6, 2, 8, 7, 6, 3, 4, 0, 10};
		
		bubbleSort(array);
		
		for(int i : array) {
			
			System.out.println(i);
		}
 	}
	
	public static void bubbleSort(int array[]) {
		
		for(int i = 0; i < array.length - 1; i++) {
			
			for(int j = 0; j < array.length - i - 1; j++) {
				
				if(array[j] > array[j + 1]) {   // >: ascending order, <: descending order
					
					int temp = array[j];
					
					array[j] = array[j + 1];
					
					array[j + 1] = temp;	
				}
			}
		}
	}
}
