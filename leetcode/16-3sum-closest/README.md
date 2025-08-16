# 3Sum Closest (LeetCode #16)

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Problem Description

Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is **closest** to `target`.  

Return the sum of the three integers.  

You may assume that each input would have exactly one solution.

---

## Examples

**Example 1:**
```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2 (-1 + 2 + 1 = 2).
```

**Example 2:**
```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0 (0 + 0 + 0 = 0).
```

---

## Constraints

- `3 <= nums.length <= 500`
- `-1000 <= nums[i] <= 1000`
- `-10^4 <= target <= 10^4`

---

## Approach

### Sorting + Two Pointers
1. Sort the input array.
2. Iterate over the array with index `i`, treating `nums[i]` as the first element of the triplet.
3. For each `i`, use two pointers (`left` and `right`) to search for the best pair:
   - Calculate the sum = `nums[i] + nums[left] + nums[right]`.
   - Update the closest sum if this sum is closer to the target.
   - If sum < target → move `left` pointer right to increase the sum.  
   - If sum > target → move `r
