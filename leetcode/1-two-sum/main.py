# PROBLEM DESCRIPTION
# 1. Two Sum
#
# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
# You can return the answer in any order.
#
# Example 1:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
#
# Example 2:
# Input: nums = [3,2,4], target = 6
# Output: [1,2]
#
# Example 3:
# Input: nums = [3,3], target = 6
# Output: [0,1]

class Solution1:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        for num1 in nums:
            j = i+1
            for num2 in nums[i+1:]:
                if (num1 + num2) == target:
                    return [i, j]
                j+=1
            i+=1

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        result = {}
        for num in nums:
            idx = target - num
            if idx in result:
                return [i, result[idx]]
            else:
                result[num] = i
            i += 1