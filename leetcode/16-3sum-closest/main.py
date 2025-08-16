# Given an integer array nums of length n and an integer target, find three integers
# in nums such that the sum is closest to target.
# Return the sum of the three integers.
# You may assume that each input would have exactly one solution.
#
# Example 1:
# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
# Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#
# Example 2:
# Input: nums = [0,0,0], target = 1
# Output: 0
# Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
#
# Constraints:
# 3 <= nums.length <= 500
# -1000 <= nums[i] <= 1000
# -104 <= target <= 104

# SOLUTION:
# runtime: 279ms, beats 94.47%
# 17.94MB, beats 31.71%
class Solution:
    def threeSumClosest(self, nums, target: int) -> int:
        nums.sort()
        nnums = len(nums)
        total = result = 0
        diff = abs(target - (nums[0] + nums[1] + nums[nnums -1]))
        print(f"begin: result = {result}")
        for lidx in range(0, nnums-1):
            ilidx = lidx + 1
            iridx = nnums - 1
            while ilidx < iridx:
                total = nums[lidx] + nums[ilidx] + nums[iridx]
                print(f"{nums[lidx]} + {nums[ilidx]} + {nums[iridx]} = {sum}")
                if total < target:
                    while (ilidx + 1 < nnums - 1 and nums[ilidx] == nums[ilidx + 1]):
                        ilidx += 1
                    ilidx += 1
                elif total > target:
                    while (iridx - 1 > ilidx and nums[iridx] == nums[iridx - 1]):
                        iridx -= 1
                    iridx -= 1
                else:
                    return total
                print(f"sum = {total} | diff = {abs(target - total)}")
                if diff >= abs(target - total):
                    diff = abs(target - total)
                    result = total
                print(f"result = {result}")
        return result
