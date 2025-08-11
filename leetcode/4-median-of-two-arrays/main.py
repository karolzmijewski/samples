# PROBLEM DESCRIPTION
# 4. Median of Two Sorted Arrays
#
# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
# The overall run time complexity should be O(log (m+n)).
#
# Example 1:
# 
# Input: nums1 = [1,3], nums2 = [2]
# Output: 2.00000
# Explanation: merged array = [1,2,3] and median is 2.

from math import floor

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        result = []
        i, j = 0, 0

        # merge sort
        if nums1 and nums2:
            while(i < len(nums1) and j < len(nums2)):
                if nums1[i] < nums2[j]:
                    print(f"+ {nums1[i]}")
                    result.append(nums1[i])
                    i += 1
                else:
                    print(f"+ {nums2[j]}")
                    result.append(nums2[j])
                    j += 1

        # add remaining rest
        if i < len(nums1):
            print(f"+ {nums1[i:]}")
            result += nums1[i:]
        elif j < len(nums2):
            print(f"+ {nums2[j:]}")
            result += nums2[j:]

        # return mediana
        print(f"result = {result}")
        result_size = len(result)
        if result_size == 1:
            return result[0]
        if result_size % 2 != 0:
            return result[floor(result_size / 2)]
        return (result[(int)(result_size / 2)] + result[(int)(result_size / 2) - 1]) / 2
