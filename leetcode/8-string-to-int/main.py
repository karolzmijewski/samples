# PROBLEM DESCRIPTION
# 8. Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
# The algorithm for myAtoi(string s) is as follows:
# Whitespace: Ignore any leading whitespace (" ").
# Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity
# if neither present.
# Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered
# or the end of the string is reached. If no digits were read, then the result is 0.
# Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the
# integer to remain in the range. Specifically, integers less than -231 should be rounded to -231,
# and integers greater than 231 - 1 should be rounded to 231 - 1.
# Return the integer as the final result.
#
# Example 1:
# Input: s = "42"
# Output: 42
# Explanation:
# The underlined characters are what is read in and the caret is the current reader position.
# Step 1: "42" (no characters read because there is no leading whitespace)
#          ^
# Step 2: "42" (no characters read because there is neither a '-' nor '+')
#          ^
# Step 3: "42" ("42" is read in)
#            ^
#
# Example 2:
# Input: s = " -042"
# Output: -42
# Explanation:
# Step 1: "   -042" (leading whitespace is read and ignored)
#             ^
# Step 2: "   -042" ('-' is read, so the result should be negative)
#              ^
# Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
#                ^
#
# Example 3:
# Input: s = "1337c0d3"
# Output: 1337
# Explanation:
# Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
#          ^
# Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
#          ^
# Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
#              ^
#
# Example 4:
# Input: s = "0-1"
# Output: 0
# Explanation:
# Step 1: "0-1" (no characters read because there is no leading whitespace)
#          ^
# Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
#          ^
# Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
#           ^
#
# Example 5:
# Input: s = "words and 987"
# Output: 0
# Explanation:
# Reading stops at the first non-digit character 'w'.

# SOLUTION 1:
# results:
# runtime: 0ms, beats 100%
# memory: 17.73MB, beats 77.57%
class Solution:
    def myAtoi(self, s: str) -> int:
        ASCII_OFFSET = 48 # "0" ASCI sign
        DIGITS_NUM = 9
        MAX_SIZE = pow(2, 31) - 1
        MIN_SIZE = -1 * (MAX_SIZE + 1)
        SPACE_ASCII_CH = 32
        MINUS_ASCII_CH = 45
        PLUS_ASCII_CH = 43

        sign = 0
        result = 0
        for ch in s:
            token = ord(ch)
            print(f"get: {ch} [{token}]")
            if token != SPACE_ASCII_CH or sign != 0:
                if token == MINUS_ASCII_CH and sign == 0:
                    sign = -1
                elif token == PLUS_ASCII_CH and sign == 0:
                    sign = 1
                else:
                    if sign == 0:
                        sign = 1
                    if token >= ASCII_OFFSET and token <= ASCII_OFFSET + DIGITS_NUM:
                        result *= 10
                        result += (token - ASCII_OFFSET)
                        if sign * result >= MAX_SIZE:
                            return MAX_SIZE
                        elif sign * result <= MIN_SIZE:
                            return MIN_SIZE
                    else:
                        return sign * result
        return sign * result


