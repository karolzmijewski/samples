# PROBLEM DESCRIPTION
# 2. Add Two Numbers
#
# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
# and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#
# Example 1:
# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode()
        p_result_start = result
        while l1 or l2:
            l1_val = l1.val if (l1) else 0
            l2_val = l2.val if (l2) else 0
            # sum digits and cr
            sum = l1_val + l2_val + result.val
            print(f"{l1_val} + {l2_val} + {result.val} % 10")
            result.val = sum % 10
            print(f"= {result.val}")
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            if sum / 10 >= 1:
                result.next = ListNode(val=1, next=None)
            else:
                # don't need to create node at all if there is nothing to add (surplus 0)
                result.next = ListNode() if l1 or l2 else None
            result = result.next
        return p_result_start
