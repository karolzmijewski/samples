# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".
#
# Example 1:
# Input: strs = ["flower","flow","flight"]
# Output: "fl"
#
# Example 2:
# Input: strs = ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
#
# Constraints:
# 1 <= strs.length <= 200
# 0 <= strs[i].length <= 200
# strs[i] consists of only lowercase English letters if it is non-empty.

class Solution:
    def longestCommonPrefix(self, strs) -> str:
        idx = 0
        prefix = ""
        while(len(strs[0]) > idx):
            p = strs[0][idx]
            for s in strs:
                if not s:
                    return ""
                if idx == len(s):
                    print(f"end of string {s}, return {prefix}")
                    return prefix
                elif p != s[idx]:
                    print(f"wrong match {p} != {s[idx]}, return {prefix}")
                    return prefix
            print(f"prefix  + {s[idx]}")
            prefix += s[idx]
            idx += 1 
        return prefix
