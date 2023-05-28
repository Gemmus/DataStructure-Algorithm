// Stack:
// - LIFO(Last-In First-Out) data structure
// - stores objects into a sort of "vertical tower"
// - push() to add to the top
// - pop() to remove from the top

// Use of stacks:
// - undo/redo features in text editors
// - moving back/forward through browser history
// - backtracking algorithms (maze, file directories)
// - calling functions (call stack)

import java.util.Stack;

public class Main{
	public static void main(String[] args){
		
		Stack<String> stack = new Stack<String>();
		
		//System.out.println(stack.empty());
		
		stack.push("Warhammer 40k");
		stack.push("Tetris");
		stack.push("Sniper Elite");
		stack.push("DOOM");
		stack.push("Borderlands");
		
		//System.out.println(stack.empty());
		
		System.out.println(stack);

		String game5 = stack.pop();
		System.out.println(stack);
		System.out.println(game5);
		
		System.out.println(stack.peek());  // to see what's on the top of the stack
			
		System.out.println(stack.search("Warhammer 40k")); // starts counting from top where top = 1; if none found, prints -1
	}
}
