/**
 * PROBLEM DESCRIPTION
 * 3. Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without duplicate characters.
 * 
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * SOLUTION 1:
 * results:
 * runtime: 20ms, beats 26.47%
 * memory: 14.38MB, beats 22.91%
 */
class Solution {
private:
    struct Node {
        Node* next = nullptr;
        char val = 0;
    };

public:
int lengthOfLongestSubstring(string s) {
    unordered_set<char> signs;
    int max_ss = 0;
    int counter = 0;
    for (int it=0; it < s.length(); ++it) {
        while(signs.find(s[it]) != signs.end()) {
            //cout << "found: " << s[it] << " c: " << counter << "\n"; 
            signs.erase(s[counter]);
            counter++;
        }
        signs.insert(s[it]);
        //cout << "add: " << s[it] << " c: " << counter << "\n";
        max_ss = max_ss < (it - counter + 1) ? it - counter + 1 : max_ss;
    }
    return max_ss;
}
};

int main() {
    Solution s;
    string test0 = "abcabcbb";
    string test1 = "bbbbb";
    string test2 = "pwwkew";
    cout << s.lengthOfLongestSubstring(test2) << "\n";
    return 0;
}