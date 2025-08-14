# PROBLEM DESCRIPTION
# 9. Given an integer x, return true if x is a palindrome, and false otherwise.
# 
# Example 1:
# Input: x = 121
# Output: true
# Explanation: 121 reads as 121 from left to right and from right to left.
# 
# Example 2:
# Input: x = -121
# Output: false
# Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
#Therefore it is not a palindrome.
#
# Example 3:
# Input: x = 10
# Output: false
# Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

# Constraints:
# -231 <= x <= 231 - 1

from math import ceil, floor

# SOLUTION 1:
# results:
# runtime: 16ms, beats 13.78% 
# memory: 18.00MB, beats 19.70%
class Solution:
    def isPalindrome(self, x: int) -> bool:
        digits = []
        if x < 0:
            return False
        if x <= 9:
            return True
        
        while(x != 0):
            digits.append(x - ((int)(x / 10)) * 10) # or digits.append(x % 10)
            x = (int)(x / 10)
        
        for i in range(0, (int)(len(digits) / 2) + 1):
            if (digits[i] != digits[(-1)*(i+1)]):
                return False
        return True

# SOLUTION 2:
# results:
# runtime: 20ms, beats 6.72%
# memory: 17.84MB, beats 39.44%
class Solution:
    def isPalindrome(self, x: int) -> bool:
        digits = []
        if x < 0:
            return False
        if x <= 9:
            return True
        i = 10
        num_digits = 1
        while(x >= i):
            i *= 10
            num_digits += 1
        i = 0
        j = 0
        mid_skip = True if num_digits % 2 != 0 else False
        mid = (int)(num_digits / 2)
        while(x != 0):
            if i < mid:
                digits.append(x % 10)
                j = i
                i += 1
            else:
                if mid_skip:
                    x = (int)(x / 10)
                    mid_skip = False
                #print(f"{x % 10} == {digits[j]} ({j}) ")
                if x % 10 != digits[j]:
                    return False
                j -= 1
            x = (int)(x / 10)
        return True

# bit polished
from math import log10
class Solution:
    def isPalindrome(self, x: int) -> bool:
        digits = []
        if x < 0:
            return False
        if x <= 9:
            return True
        i = 0
        j = 0
        num_digits = int(log10(x)) + 1
        mid_skip = True if num_digits % 2 != 0 else False
        mid = num_digits // 2
        while(x != 0):
            if i < mid:
                digits.append(x % 10)
                j = i
                i += 1
            else:
                if mid_skip:
                    x //= 10
                    mid_skip = False
                #print(f"{x % 10} == {digits[j]} ({j}) ")
                if x % 10 != digits[j]:
                    return False
                j -= 1
            x = x // 10
        return True

# SOLUTION 3
# runtime: 9ms, beats 44.25%
# results: 18.01MB, beats 19.70%
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x < 10:
            return True
        
        num_digits = int(math.log10(x)) + 1
        msd_mask = 10 ** (num_digits - 1)
        
        for _ in range(num_digits // 2):
            most_significant = x // msd_mask
            least_significant = x % 10
            if most_significant != least_significant:
                return False
            
            # mod will remove most significant digit, div will remove less significant
            # if there will be zeros on the way for instance 10021 we will get 2 that's fine because
            # 2 % 10 is 2 but for instance 2 // 100 (reduced mask <- 10000 // 100 = 100) will give 0
            # so 2 != 0
            x = (x % msd_mask) // 10
            msd_mask //= 100
        
        return True
