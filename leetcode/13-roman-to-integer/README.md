# Roman to Integer

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Problem Description

Roman numerals are represented by seven different symbols:

| Symbol | Value |
|--------|-------|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

For example:  
- 2 is written as `II` (two ones added together).  
- 12 is written as `XII` (X + II).  
- 27 is written as `XXVII` (XX + V + II).

Roman numerals are usually written from largest to smallest from left to right. However, in some cases subtraction is used instead of addition:

- The numeral for **4** is `IV` (one before five, so we subtract 1 from 5).
- The numeral for **9** is `IX` (one before ten, so we subtract 1 from 10).

There are **six cases** where subtraction is used:
1. `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
2. `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
3. `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

**Task**: Given a Roman numeral string `s`, convert it to an integer.

---

## Examples

**Example 1:**
```
Input: s = "III"
Output: 3
Explanation: III = 3
```

**Example 2:**
```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V = 5, III = 3
```

**Example 3:**
```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90, IV = 4
```

---

## Constraints

- `1 <= s.length <= 15`
- `s` contains only the characters `'I'`, `'V'`, `'X'`, `'L'`, `'C'`, `'D'`, `'M'`.
- It is guaranteed that `s` is a valid Roman numeral in the range `[1, 3999]`.

---

## Approach

The algorithm processes the string from left to right, using a mapping of symbols to values:

1. If the current symbol represents a value **less** than the next symbol’s value, subtract it from the total (this handles the subtractive cases).
2. Otherwise, add the current symbol’s value to the total.
3. Continue until all symbols are processed.

**Example walkthrough (MCMXCIV):**  
- M (1000) → add → total = 1000  
- C (100) before M (1000) → subtract → total = 900  
- M (1000) → add → total = 1900  
- X (10) before C (100) → subtract → total = 1890  
- C (100) → add → total = 1990  
- I (1) before V (5) → subtract → total = 1994

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

## References

- [LeetCode Problem #13 – Roman to Integer](https://leetcode.com/problems/roman-to-integer/)
