# Clone Graph

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Problem Description

Given a reference of a node in a connected **undirected graph**, return a deep copy (clone) of the graph.  

Each node in the graph contains:
- an integer `val`
- a list `neighbors` (List[Node]) representing its adjacent nodes.

```java
class Node {
    public int val;
    public List<Node> neighbors;
}
```

### Test Case Format
- Each node’s value is the same as its index (1-indexed).  
  Example: the first node has `val = 1`, the second node has `val = 2`, etc.
- The graph is represented using an **adjacency list**, where each list describes the neighbors of a node.
- The given node will always be the first node with `val = 1`.
- You must return the copy of the given node as a reference to the cloned graph.

---

## Examples

**Example 1:**
```
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation:
There are 4 nodes in the graph.
- 1st node (val = 1) has neighbors 2 and 4.
- 2nd node (val = 2) has neighbors 1 and 3.
- 3rd node (val = 3) has neighbors 2 and 4.
- 4th node (val = 4) has neighbors 1 and 3.
```

**Example 2:**
```
Input: adjList = [[]]
Output: [[]]
Explanation:
The graph consists of a single node (val = 1) with no neighbors.
```

---

## Constraints

- The number of nodes in the graph is in the range `[0, 100]`.
- `1 <= Node.val <= 100`
- `Node.val` is unique for each node.
- No repeated edges and no self-loops.
- The graph is connected, and all nodes can be visited starting from the given node.

---

## Approach

### Graph Traversal (DFS or BFS)
To clone the graph:
1. Use a hash map (dictionary) to store the mapping from original nodes to their clones.
2. Perform a DFS or BFS traversal:
   - If a node has not been cloned yet, create its clone and add it to the map.
   - Recursively (or iteratively) visit all neighbors and link their cloned versions.
3. Return the clone of the starting node.

This ensures that each node is cloned exactly once and cycles in the graph are handled properly.

**Time Complexity:** O(V + E)  
**Space Complexity:** O(V) (for the hash map and recursion/queue)

---

## References

- [LeetCode Problem #133 – Clone Graph](https://leetcode.com/problems/clone-graph/)
