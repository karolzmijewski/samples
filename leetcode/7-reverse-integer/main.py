# PROBLEM DESCRIPTION
# 7. Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes
# the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
# Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
#
# Example 1:
# Input: x = 123
# Output: 321
#
# Example 2:
# Input: x = -123
# Output: -321
#
# Example 3:
# Input: x = 120
# Output: 21

# SOLUTION 1:
# results:
# runtime: 44ms, beats 23.92%
# memory: 17.56MB, beats 97.29%
class Solution:
    def reverse(self, x: int) -> int:
        MAX_SIZE = pow(2, 31) -1
        MIN_SIZE = -1 * (MAX_SIZE +1)
        if x >= 0:
            result = (int) ( str(x)[::-1] ) 
            return result if result <= MAX_SIZE else 0
        result = -1 * (int)( str(x)[:0:-1] )
        return result if result >= MIN_SIZE else 0
