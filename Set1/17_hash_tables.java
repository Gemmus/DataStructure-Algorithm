// Hash Tables: 
// A data structure that stores uniques keys to values ex.<Integer, String>.
// Each key/value pair is known as an Entry.
// FAST insertion, look up, deletion of key/value pairs.
// Not ideal for small data sets, great with large data sets.

// Hashing = takes a key and computes an integer (formula will vary based on key & data type).
// In  a Hashtable, we uses the hash % capacity to calculate an index number:
// 		                                      key.hashCode() % capacity = index

// Bucket = an indexed storage location for one or more Entries.
// Can store multiple Entries in case of a collision (linked similarly a LinkedList).

// Collision = hash funtion generates the same index for more than one key.
// Less collision = more efficiency.

// Runtime complexity: Best Case O(1)
// 					           Worst Case O(n)

import java.util.*;

public class Main{
	
	public static void main(String[] args) {

		////////////////////////////////////////////////////
		// Creating Hash Table with Integer and String:   //
		////////////////////////////////////////////////////
		
		//by standard: (11, 0.75f) = (capacity, load factor), where load factor = 75%, dynamically expends, if load exceeded 
		Hashtable<Integer, String> table1 = new Hashtable<>(10);
		
		// Adding key, value:
		table1.put(100, "Joe");
		table1.put(123, "Lara"); 
		table1.put(321, "Bob"); 
		table1.put(555, "Jack"); 
		table1.put(777, "Zoe"); 
		
		// Removing an entry: 
		table1.remove(777);
		
		// Accessing the values:
		System.out.println(table1.get(100));
		// or 
		for(Integer key : table1.keySet()) {
			//System.out.println(key.hashCode() + "\t" + key + "\t" + table.get(key));
			System.out.println(key.hashCode() % 10 + "\t" + key + "\t" + table1.get(key)); // % 10: refers to the size of the bucket
		}
		
		System.out.println();
		
		///////////////////////////////////////////////////
		// Creating Hash Table with String and String:   //
		///////////////////////////////////////////////////
		
		//by standard: (11, 0.75f) = (capacity, load factor), where load factor = 75%, dynamically expends, if load exceeded 
		Hashtable<String, String> table2 = new Hashtable<>(10);
		
		// Adding key, value:
		table2.put("100", "Joe");
		table2.put("123", "Lara"); 
		table2.put("321", "Bob"); 
		table2.put("555", "Jack"); 
		table2.put("777", "Zoe"); 
		
		// Removing an entry: 
		table2.remove("777");
		
		// Accessing the values:
		System.out.println(table2.get("100"));
		// or 
		for(String key : table2.keySet()) {
			//System.out.println(key.hashCode() + "\t" + key + "\t" + table.get(key));
			System.out.println(key.hashCode() % 10 + "\t" + key + "\t" + table2.get(key)); // 1 collision occurs, which is be treated as LinkedList, to avoid collisions, the size of the hash can be changed, but uses more memory
		}
	}
}
