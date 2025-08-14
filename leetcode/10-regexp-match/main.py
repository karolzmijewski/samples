# PROBLEM DESCRIPTION
# Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
# '.' Matches any single character.​​​​
# '*' Matches zero or more of the preceding element.
# The matching should cover the entire input string (not partial).
#
# Example 1:
# Input: s = "aa", p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
#
# Example 2:
# Input: s = "aa", p = "a*"
# Output: true
# Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
#
# Example 3:
# Input: s = "ab", p = ".*"
# Output: true
# Explanation: ".*" means "zero or more (*) of any character (.)".
#
# Constraints:
# 1 <= s.length <= 20
# 1 <= p.length <= 20
# s contains only lowercase English letters.
# p contains only lowercase English letters, '.', and '*'.
# It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

# SOLUTION 1
# runtime: 4ms, beats 84.57%
# results: 18.12MB, beats 13.81%
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        @lru_cache(None)
        def _verifyPattern(s_pos, p_pos):
            # End of pattern
            if p_pos == len(p):
                print(f"pattern end at pos: {p_pos}")
                if s_pos == len(s):
                    print(f"string end at pos: {s_pos}")
                    return True
                else:
                    return False

            s_char = s[s_pos] if s_pos < len(s) else "<END>"
            p_char = p[p_pos] if p_pos < len(p) else "<END>"
            print(f"s[{s_pos}] = '{s_char}' || p[{p_pos}] = '{p_char}'")

            # Look ahead for '*'
            if p_pos + 1 < len(p) and p[p_pos + 1] == "*":
                if s_pos < len(s) and (p[p_pos] == s[s_pos] or p[p_pos] == '.'):
                    # ZERO MATCH: skip ch* and continue
                    skip_result = _verifyPattern(s_pos, p_pos + 2)
                    # ONE OR MORE MATCH: consume ch from str that maches ch* and continue
                    verify_result = _verifyPattern(s_pos + 1, p_pos)
                    return skip_result or verify_result 
                else:
                    # ZERO MATCH: the only possibility because ch*  were ch != xx and ch != .
                    return _verifyPattern(s_pos, p_pos + 2)

            # NORMAL MATCH: No '*'
            if s_pos < len(s) and (p[p_pos] == s[s_pos] or p[p_pos] == '.'):
                return _verifyPattern(s_pos + 1, p_pos + 1)
            return False

        # Shortcut for no "." or "*"
        if "*" not in p and "." not in p:
            return s == p

        return _verifyPattern(0, 0)
