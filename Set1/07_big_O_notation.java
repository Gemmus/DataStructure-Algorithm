// Big O notation: How code slows as data grows.

// 1. Describes the performance of an algorithm as the amount of data increases
// 2. Machine independent ( # of steps to completion)
// 3. Ignore smaller operations 0(n + 1) -> O(n)

// example: O(1), O(n), O(log n), O(n²), etc. where n = amount of data

// O(n): linear time       -->   n = 1000000 --> 1000000 steps

int addUp(int n){
	
	int sum = 0;
	for(int i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}

// O(1): constant time     -->   n = 1000000 --> 3 steps

int addUp(int n) {
	
	int sum = n * (n + 1) / 2;
	return sum;
}
