// Queue:
// - FIFO(First-In First-Out) data structure ~ "a line of people": first-come, first-served
// - a collection designed for holding elements prior processing
// - linear data structure
// - add = enqueue, offer()
// - remove = dequeue, poll()

// Use of queue:
// - keyboard buffer
// - printer queue
// - LinkedLists, PriorityQueues, Breadth-first search

import java.util.Queue;
import java.util.LinkedList;

public class Main{
	public static void main(String[] args){
		
		Queue<String> queue = new LinkedList<String>();
		
		queue.offer("Karen");
		queue.offer("Steve");
		queue.offer("Chad");
		queue.offer("Harold");
		System.out.println(queue.isEmpty());
		System.out.println(queue.size());
		
		System.out.println(queue.peek());
		System.out.print(queue.contains("Harold"));
				
		queue.poll();
		System.out.println(queue);
	}
}
