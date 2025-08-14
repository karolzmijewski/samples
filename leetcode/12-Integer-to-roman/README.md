# Integer to Roman

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

## Problem Description

Seven different symbols represent Roman numerals with the following values:

| Symbol | Value |
|--------|-------|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral follows these rules:

1. **General case**:  
   If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the number, append that symbol to the result, subtract its value, and convert the remainder.

2. **Subtractive form**:  
   If the value starts with 4 or 9, use the subtractive form — one symbol subtracted from the next highest symbol.  
   The only subtractive forms are:  
   - 4 → IV  
   - 9 → IX  
   - 40 → XL  
   - 90 → XC  
   - 400 → CD  
   - 900 → CM  

3. **Repetition rule**:  
   - Only the symbols representing powers of 10 (`I`, `X`, `C`, `M`) can be repeated consecutively up to 3 times.  
   - Symbols for 5 (`V`), 50 (`L`), and 500 (`D`) cannot be repeated.  
   - If you need to append a symbol 4 times, use the subtractive form.

**Task**: Given an integer, convert it to a Roman numeral.

---

## Examples

**Example 1:**
```
Input: num = 3
Output: "III"
```

**Example 2:**
```
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3 → LVIII
```

**Example 3:**
```
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90, IV = 4
```

---

## Constraints

- `1 <= num <= 3999`

---

## Approach

A straightforward solution is to use a **mapping of integer values to Roman numeral symbols** (including subtractive cases), then iterate from the largest to the smallest:

1. Define pairs of values and symbols, e.g. `(1000, 'M'), (900, 'CM'), (500, 'D'), ... , (1, 'I')`.
2. While the number is greater than or equal to the current value:
   - Append the corresponding symbol to the result.
   - Subtract the value from the number.
3. Continue until the number becomes zero.

This greedy approach ensures that we always use the largest possible symbol at each step, producing the correct Roman numeral.

**Time Complexity:** O(1) (bounded by a fixed set of Roman numeral values)  
**Space Complexity:** O(1)

---

## References

- [LeetCode Problem #12 – Integer to Roman](https://leetcode.com/problems/integer-to-roman/)
