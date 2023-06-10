// Graph:
// Can model a network.
// Non-linear aggregation of Nodes (or Vertex) and Edges.
// Nodes: contains some data
// Edge: the connection between two nodes

// Can be undirected or directed (one way connection). 
// Adjacency: when two nodes are connected.

// Two common ways to represent the graphs:
// 1. Adjacency matrix:
// - 2D array
// - fast to look up an edge, but uses a lot of rooms --> suits grasphs that have a lot of edges
// - time complexity: O(1)
// - space complexity: O(V²)

// 2. Adjacency list:
// - array of LinkedList, where each node is a seperate list
// - slower, but uses less space
// - time complexity: O(V)
// - space complexity: O(V + E)
