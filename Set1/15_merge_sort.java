// Merge Sort: O(n log n) =  quasilinear time
// Recursively divide array in 2, sort, re-combine.
// Space complexity = O(n).

public class Main{
	
	public static void main(String[] args) {

		int[] array = {8, 6, 3, 9, 4, 5, 1, 7, 2};
		
		mergeSort(array);
		
		for(int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}
	}
	
	private static void mergeSort(int[] array) {
		int length = array.length;
		
		// Base Case:
		if (length <= 1) return; 
		
		int middle = length / 2;
		int[] leftArray = new int[middle];
		int[] rightArray = new int[length - middle];
		
		int i = 0;
		int j = 0;
		
		for(; i < length; i++) {
			if (i < middle) {
				leftArray[i] = array[i];
			}
			else {
				rightArray[j] = array[i];
				j++;
			}
		}
		
		// Recursive Case:
		mergeSort(leftArray);
		mergeSort(rightArray);
		Merge(leftArray, rightArray, array);
 	}
	
	private static void Merge(int[] leftArray, int[] rightArray, int[] array) {
		
		int leftSize = array.length / 2;
		int rightSize = array.length - leftSize;
		int i = 0, l = 0, r = 0; // indices
		
		// Checking the conditions for merging:
		while(l < leftSize && r < rightSize) {
			if(leftArray[l] < rightArray[r]) {
				array[i] = leftArray[l];
				i++;
				l++;
			}
			else {
				array[i] = rightArray[r];
				i++;
				r++;
			}
		}
		while(l < leftSize) {
			array[i] = leftArray[l];
			i++;
			l++;
		}
		while(r < rightSize) {
			array[i] = rightArray[r];
			i++;
			r++;
		}
	}
}
