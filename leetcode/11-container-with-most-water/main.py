# PROBLEM DESCRIPTION
# 11. You are given an integer array height of length n. There are n vertical lines drawn such that
# the two endpoints of the ith line are (i, 0) and (i, height[i]).
# Find two lines that together with the x-axis form a container, such that the container contains
# the most water.
# Return the maximum amount of water a container can store.
# Notice that you may not slant the container.
#
# Example 1:
# Input: height = [1,8,6,2,5,4,8,3,7]
# Output: 49
# Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
#
# Example 2:
# Input: height = [1,1]
# Output: 1

# runtime: 51ms, beats 95.57%
# memory: 28.48MB, beats 67.74%
class Solution:
    def maxArea(self, height) -> int:
        lidx = 0
        ridx = len(height) -1
        max_h = 0
        max_sq = 0

        while (lidx != ridx):
            print(f"check: [{height[lidx]} or {height[ridx]}] * [{ridx - lidx}]")
            curr_h = height[lidx] if height[lidx] < height[ridx] else height[ridx]
            curr_sq = curr_h * (ridx - lidx)
            print(f"select: {curr_h} * {ridx - lidx} = {curr_sq}")
            max_sq = curr_sq if curr_sq > max_sq else max_sq

            rd = height[ridx] #- height[ridx - 1]
            ld = height[lidx] #- height[lidx + 1]

            if ld < rd:
                lidx += 1
            else:
                ridx -= 1
        
        return max_sq

height = [1,8,6,2,5,4,8,3,7]
height = [1,3,2,5,25,24,5]
height = [159,157,139,51,98,71,4,125,48,125,64,4,105,79,136,169,113,13,95,88,190,5,148,17,152,20,196,141,35,42,188,147,199,127,198,49,150,154,175,199,80,191,3,137,22,92,58,87,57,153,175,199,110,75,16,62,96,12,3,83,55,144,30,6,23,28,56,174,183,183,173,15,126,128,104,148,172,163,35,181,68,162,181,179,37,197,193,85,10,197,169,17,141,199,175,164,180,183,90,115]
sol = Solution()
sol.maxArea(height)
