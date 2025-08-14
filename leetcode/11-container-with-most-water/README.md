# Container With Most Water

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Problem Description

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the *i*-th line are `(i, 0)` and `(i, height[i])`.

Find two lines that, together with the x-axis, form a container such that the container holds the maximum amount of water.

**Note:** The container cannot be slanted.

---

## Examples

**Example 1:**

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
```

Explanation:  
The above vertical lines are represented by the array `[1,8,6,2,5,4,8,3,7]`.  
In this case, the maximum area of water the container can store is **49**.

---

**Example 2:**

```
Input: height = [1,1]
Output: 1
```

---

## Constraints

- `n >= 2`
- `0 <= height[i] <= 10^4`

---

## Approach

This problem can be solved efficiently using the **two-pointer technique**:

1. Start with two pointers — one at the beginning (`left`) and one at the end (`right`).
2. Compute the area as:  
   ```
   area = min(height[left], height[right]) * (right - left)
   ```
3. Update the maximum area if the current area is larger.
4. Move the pointer pointing to the shorter line inward (to try to find a taller line).
5. Repeat until `left` and `right` meet.

This approach runs in **O(n)** time and uses **O(1)** extra space.

---

## Performance

- **Runtime:** 51 ms (beats 95.57% of submissions)
- **Memory:** 28.48 MB (beats 67.74% of submissions)

---

## References

- [LeetCode Problem #11 – Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
