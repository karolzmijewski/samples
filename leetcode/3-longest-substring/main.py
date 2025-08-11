# PROBLEM DESCRIPTION
# 3. Longest Substring Without Repeating Characters
#
# Given a string s, find the length of the longest substring without duplicate characters.
#
# Example 1:
# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.

# Time Limit Exceeded
# 987 / 988 testcases passed
class Solution1:
    def lengthOfLongestSubstring(self, s: str) -> int:
        substrs = ""
        length = 0
        result = 0
        i = 1
        r = range(0, len(s))
        for i in r:
            if result == len(s):
                break
            for ch in s[i:]:
                if not ch in substrs:
                    substrs += ch
                    length += 1
                    result = length if length > result else result
                else:
                    substrs = ch
                    length = 1
            substrs = ""
            length = 0
        return result

# slicing windows - unique substrings
# going from right if the character was already spotted previously
# we are removing characters from left until we can add this character as unique
# in the worst case we will remove all until this character and start counting new substring
# from beginning, but sometimes only a part of string can be removed to make a substring unique
# and we can continue with counting
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ss = ""
        length = 0
        result = 0
        for ch in s:
            if ch in ss:
                while(ch in ss):
                    ss = ss[1:]
                    length -= 1
            ss += ch
            length += 1
            result = length if length > result else result
        return result
