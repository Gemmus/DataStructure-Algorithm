// Recursion:
// When a thing is defined in terms of itself.
// Apply the result of a procedure, to a procedure.
// A recursive method calls itself. Can be a substitute for iteration.
// Divide a problem into sub-problems of the same type as the original.
// Commonly used with advanced sorting algorithms and navigating trees.

// Advantages: 
// - easier to read/write
// - easier to debug

// Disadvantages:
// - sometimes slower (call stack)
// - uses more memory

/*                                ITERATION                              RECURSION
***************************************************************************************************
IMPLEMENTATION    |               uses loops            |              calls itself
***************************************************************************************************
STATE             |    control index (int steps = 0)    |     parameter values walk(int steps)
***************************************************************************************************
PROGRESSION       |   moves toward value in condition   |        converge towards base case
***************************************************************************************************
TERMINATION       |      index satisfies condition      |             base case = true
***************************************************************************************************
SIZE              |       more code, less memory        |           less code, more memory
***************************************************************************************************
SPEED             |                 faster              |                  slower
*/

public class Main{
	
	public static void main(String[] args) {
		
		walk(5);
		
		System.out.println(factorial(9));
		
		System.out.println(power(2, 8));
	}
	
	private static void walk(int steps) {
		
		// Base case: 	
		if(steps < 1) return;
		
		// Recursive case: 
		System.out.println("You took a step!");
		walk(steps - 1);
		
	}
	
	private static int factorial(int number) {
		
		// Base case:
		if(number < 1) return 1;
		
		// Recursive case:
		return number * factorial(number - 1);
	}
	
	private static int power(int base, int exponent) {
		
		// Base case:
		if(exponent < 1) return 1;
		
		// Recursive case:
		return base * power(base, exponent -1);
	}
}
