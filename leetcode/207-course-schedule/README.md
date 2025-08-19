# Course Schedule

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Problem Description

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`.  

You are given an array `prerequisites` where `prerequisites[i] = [a_i, b_i]` indicates that you must take course `b_i` first if you want to take course `a_i`.

- For example, the pair `[0, 1]` means that to take course `0`, you must first complete course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

---

## Examples

**Example 1:**
```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses.
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**
```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. This forms a cycle, so it is impossible.
```

---

## Constraints

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= a_i, b_i < numCourses`
- All prerequisite pairs are unique.

---

## Approach

This problem can be modeled as detecting whether a **directed graph** has a cycle.

1. **Graph Representation**  
   - Represent courses as graph nodes.
   - Use adjacency lists to represent prerequisites (`b -> a` edges).

2. **Cycle Detection**  
   - If the graph has a cycle, it is impossible to finish all courses.
   - Cycle detection can be done with:
     - **DFS with visited states** (0 = unvisited, 1 = visiting, 2 = visited).
     - **Kahn’s Algorithm (Topological Sort using BFS)**.

3. **Return Result**  
   - If a cycle is found → return `false`.
   - Otherwise → return `true`.

### Complexity
- **Time Complexity:** O(V + E), where V = number of courses, E = number of prerequisites.  
- **Space Complexity:** O(V + E), for adjacency list and recursion/queue.

---

## References

- [LeetCode Problem #207 – Course Schedule](https://leetcode.com/problems/course-schedule/)
