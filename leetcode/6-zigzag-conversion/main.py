# PROBLEM DESCRIPTION
# 6. The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
# (you may want to display this pattern in a fixed font for better legibility)
#
# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion given a number of rows:
# string convert(string s, int numRows);
#
# Example 1:
#     Input: s = "PAYPALISHIRING", numRows = 3
#     Output: "PAHNAPLSIIGYIR"
# Example 2:
#     Input: s = "PAYPALISHIRING", numRows = 4
#     Output: "PINALSIGYAHRPI"
#     Explanation:
#     P     I    N
#     A   L S  I G
#     Y A   H R
#     P     I

# SOLUTION 1:
# results:
# runtime: 15ms, beats 37.23%
# memory:  17.87MB, beats 69.48%
class Solution(object):
    def convert(self, s, num_rows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        rtree = {}
        idx = 0
        direction = -1
        for i in range(0, len(s)):
            if idx == num_rows-1 or idx == 0:
                direction *= -1
                print(f"change direction: {direction}")
            if not idx in rtree:
                rtree[idx] = ""
            print(f"{idx} += {s[i]}[{i}]")
            rtree[idx] += s[i]
            idx += direction
        result = ""
        for row_id, row_val in rtree.items():
            print(f"{row_id}: {row_val}")
            result += row_val
        return result
        