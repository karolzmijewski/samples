/**
 * PROBLEM DESCRIPTION
 * 2. Add Two Numbers
 * 
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
 * and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 */

#include <iostream>
#include <sstream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * SOLUTION 1:
 * DOESNT WORK FOR HUGE NUMBERS
 */
class Solution1 {
private:
    unsigned long long getValue(ListNode* list) {
        string result = "";
        while(list->next != nullptr) {
            result = to_string(list->val) + result;
            list = list->next;
        }
        result = to_string(list->val) + result; 
        return stoull(result);
    }
    ListNode* setValue(unsigned long long value) {
        string svalue = to_string(value);
        ListNode* result = nullptr;
        for (auto it = svalue.begin(); it != svalue.end(); ++it) {
            ListNode* ln = new ListNode(static_cast<int>(*it - '0'));
            ln->next = result;
            result = ln; 
        }
        return result;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long long result = getValue(l1) + getValue(l2);
        return setValue(result);
    }
};

/**
 * SOLUTION 2:
 * Very primitive
 * results:
 * runtime: 11ms, beats 5.39%
 * memory: 76.96MB, beats 91.55%
 */
class Solution2 {
public:
    unsigned long long getValue(ListNode* list) {
        string result = "";
        while(list->next != nullptr) {
            result = to_string(list->val) + result;
            list = list->next;
        }
        result = to_string(list->val) + result; 
        return stoull(result);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* it = new ListNode();
        ListNode* head = it;
        int sum = 0;
        while((l1 || l2) || sum ) {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            it->val = static_cast<int>(sum % 10);
            sum = static_cast<int>(sum / 10);
            if (((l2 || l1 )) || sum ) {
                it->next = new ListNode();
                it = it->next;
            }
        }
        return head;
    }
};

int main() {
    // testcase1
    ListNode ln11(3);
    ListNode ln12(4, &ln11);
    ListNode ln13(2, &ln12);

    ListNode ln21(4);
    ListNode ln22(6, &ln21);
    ListNode ln23(5, &ln22);

    Solution2 s;
    ListNode* ln = s.addTwoNumbers(&ln13, &ln23);
    cout << s.getValue(ln) << "\n";
    
    while(ln->next != nullptr) {
        ListNode* ptr = ln;
        ln = ln->next;
        delete(ptr);
    }
    delete(ln);

    return 0;
}