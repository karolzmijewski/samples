# PROBLEM DESCRIPTION
# 12. Seven different symbols represent Roman numerals with the following values:
# Symbol    Value
# I	1
# V	5
# X	10
# L	50
# C	100
# D	500
# M	1000
#
# Roman numerals are formed by appending the conversions of decimal place values
# from highest to lowest. Converting a decimal place value into a Roman numeral
# has the following rules:
# - If the value does not start with 4 or 9, select the symbol of the maximal value
#   that can be subtracted from the input, append that symbol to the result, subtract
#   its value, and convert the remainder to a Roman numeral.
# - If the value starts with 4 or 9 use the subtractive form representing one symbol
#   subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV
#   and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used:
#   4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
# - Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to
#   represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times.
#   If you need to append a symbol 4 times use the subtractive form.
# Given an integer, convert it to a Roman numeral.

# SOLUTION
# runtime: 3ms, beats 79.08%
# memory: 17.70MB, beats 91.72%
class Solution:
    def intToRoman(self, num: int) -> str:
        rsymb = {1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: "M"}
        FIVE_IDX_STEP = 5 # to move from units to fives (unit * 5)
        TEN_IDX_STEP = 10 # to move from units to tens (unit * 10)
        LRANGE = 4
        RRANGE = 9
        div = 1000
        rval = ""

        while num and div:
            x = num // div
            print(f"x={x}, div={div}")
            if x != 0:
                if x == RRANGE:
                    print(f"+ {rsymb[div]}{rsymb[div * TEN_IDX_STEP]}")
                    rval += rsymb[div] + rsymb[div * TEN_IDX_STEP]
                elif x < RRANGE and x > LRANGE:
                    print(f"+ {rsymb[div * FIVE_IDX_STEP]}")
                    rval += rsymb[div * FIVE_IDX_STEP]
                    for _ in range(LRANGE + 1, x):
                        print(f"+ {rsymb[div]}")
                        rval += rsymb[div]
                elif x == LRANGE:
                    print(f"+ {rsymb[div]}{rsymb[div * FIVE_IDX_STEP]}")
                    rval += rsymb[div] + rsymb[div * FIVE_IDX_STEP]
                elif x < LRANGE:
                    for _ in range(0, x):
                        print(f"+ {rsymb[div]}")
                        rval += rsymb[div]
                num %= div
            div //=  10
        return rval
