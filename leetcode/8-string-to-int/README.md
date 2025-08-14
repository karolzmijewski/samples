# String to Integer (myAtoi)

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

---

## Problem Description

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer.

The algorithm for `myAtoi(string s)` is as follows:

1. **Whitespace:** Ignore any leading whitespace (`" "`).
2. **Signedness:** Determine the sign by checking if the next character is '-' or '+', assuming positive if neither is present.
3. **Conversion:** Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, the result is 0.
4. **Rounding:** If the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, then round the integer to remain in the range.

   * Integers less than `-2^31` should be rounded to `-2^31`.
   * Integers greater than `2^31 - 1` should be rounded to `2^31 - 1`.

Return the integer as the final result.

---

## Example 1

**Input:**

```
s = "42"
```

**Output:**

```
42
```

**Explanation:** Reading stops after "42" with no leading whitespace or sign.

---

## Example 2

**Input:**

```
s = " -042"
```

**Output:**

```
-42
```

**Explanation:** Leading whitespace is ignored; '-' sign is detected; "042" is read.

---

## Example 3

**Input:**

```
s = "1337c0d3"
```

**Output:**

```
1337
```

**Explanation:** Reading stops at the first non-digit character 'c'.

---

## Example 4

**Input:**

```
s = "0-1"
```

**Output:**

```
0
```

**Explanation:** Only the leading '0' is read; reading stops before '-'.

---

## Example 5

**Input:**

```
s = "words and 987"
```

**Output:**

```
0
```

**Explanation:** Reading stops at the first non-digit character 'w'.

---

## Related Links

* [LeetCode Problem Link](https://leetcode.com/problems/string-to-integer-atoi/)
