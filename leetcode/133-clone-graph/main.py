# Given a reference of a node in a connected undirected graph.
# Return a deep copy (clone) of the graph.
# Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
#
# class Node {
#     public int val;
#     public List<Node> neighbors;
# }
#
# Test case format:
# For simplicity, each node's value is the same as the node's index (1-indexed). For example, 
# the first node with val == 1, the second node with val == 2, and so on. The graph is 
# represented in the test case using an adjacency list.
# An adjacency list is a collection of unordered lists used to represent a finite graph.
# Each list describes the set of neighbors of a node in the graph.
# The given node will always be the first node with val = 1. You must return the copy of
# the given node as a reference to the cloned graph.,
#
# Example 1:
# Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
# Output: [[2,4],[1,3],[2,4],[1,3]]
# Explanation: There are 4 nodes in the graph.
# 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
# 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
# 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
# 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
# 
# Example 2:
# Input: adjList = [[]]
# Output: [[]]
# Explanation: Note that the input contains one empty list. The graph consists of only one
# node with val = 1 and it does not have any neighbors.
#
# Constraints:
# The number of nodes in the graph is in the range [0, 100].
# 1 <= Node.val <= 100
# Node.val is unique for each node.
# There are no repeated edges and no self-loops in the graph.
# The Graph is connected and all nodes can be visited starting from the given node.

from typing import Optional

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

# SOLUTION
# DFS (Deep First Search)
# runtime: 41ms, beats 72.89%
# memory: 18.21MB, beats 39.61%
class Solution:
    def cloneGraph(self, node):
        _visited = {}
        def ndeepcopy(src_node):
            if src_node != None and not src_node.val in _visited:
                dst_node = Node()
                dst_node.val = src_node.val
                _visited[dst_node.val] = dst_node
                for nn in src_node.neighbors:
                    dst_n_node = ndeepcopy(nn)
                    dst_node.neighbors.append(dst_n_node)
                return dst_node
            elif src_node.val in _visited:
                return _visited[src_node.val]
        if node:
            return ndeepcopy(node)
        return None


# SOLUTION
# BFS (Deep First Search)
# runtime: 39ms, beats 81.43%
# memory: 18.28MB, beats 39.61%
class Solution:
    def cloneGraph(self, node):
        processed = {}
        def ndeepcopy(src_node):
            dst_node = Node()
            dst_node.val = src_node.val
            pq = []
            for nn in src_node.neighbors:
                pq.append(nn)
            processed[dst_node.val] = dst_node
            while pq:
                node = pq.pop()
                if not node.val in processed:
                    cp_node = ndeepcopy(node)
                    dst_node.neighbors.append(cp_node)
                else:
                    dst_node.neighbors.append(processed[node.val])
            return dst_node
        
        if node:
            return ndeepcopy(node)
        return None



n1 = Node(1)
n2 = Node(2)
n3 = Node(3)
n4 = Node(4)

n1.neighbors.append(n2)
n1.neighbors.append(n4)
n2.neighbors.append(n1)
n2.neighbors.append(n3)
n3.neighbors.append(n2)
n3.neighbors.append(n4)
n4.neighbors.append(n1)
n4.neighbors.append(n3)

sol = Solution()
n = sol.cloneGraph(n1)