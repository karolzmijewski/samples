/**
 * PROBLEM DESCRIPTION
 *
 * 5. Longest Palindromic Substring
 * 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * SOLUTION 1:
 * Brute Force O(n^2) - First attempt
 * results: timeout
 */
class Solution1 {
public:
    string longestPalindrome(string s) {
        vector<string> ss_container {};
        int offset = 1;
        // step 1: collect all substrings in vector
        for (auto head = s.begin(); head < s.end(); ++head) {
            stringstream ss { };
            ss << *head;
            ss_container.push_back(ss.str());
            for (auto tail = s.begin() + offset; tail < s.end(); ++tail) {
                ss << *tail;
                ss_container.push_back(ss.str());
            }
            ++offset;
        }

        // step 2: find the longest palidrome in substrings
        int max = 0;
        string result = "";
        for (string substr : ss_container) {
            //cout << substr << "\n";
            if (max < substr.size()) {
                string original = substr;
                reverse(substr.begin(), substr.end());
                if (original == substr) {
                    max = original.size();
                    result = original;
                }
            }
        }
        return result;
    }
};

/**
 * SOLUTION 2:
 * Brute Force O(n^2)
 * - removed vector as far as there is no need to collect all substrings in container
 * - removed std calls to reverse substrings to verify palidrome
 * results: timeout
 */
class Solution2 {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int offset = 0;
        string result = "";
        for (auto head = s.begin(); head < s.end(); ++head) {
            string ss = "";
            string rss = "";
            int ss_size = 0;
            for (auto tail = s.begin() + offset; tail < s.end(); ++tail) {
                // create new substring by adding new character to the previous substring
                ss += *tail;
                // at the same time create reversed substring to verify palindromic
                rss = *tail + rss;
                // use counter to remove calling size each time on each substring
                ++ss_size;
                if (max < ss_size) {
                    if (ss == rss) {
                        max = ss_size;
                        result = ss;
                    }
                }
            }
            if (result.size() == s.size()) {
                return result;
            }
            // move head pointer of string to the next char 
            // (remove very first char and repeate substring generation)
            ++offset;
        }
        return result;
    }
};

/**
 * SOLUTION 3:
 * Brute Force O(n^2)
 * - reverse generation of substring (instead of starting from the shortest, start from the longest possible)
 * it makes possible to end iteration earlier, as far as it's impossible to find longer substring in next iteration
 * - use std calls to create substrings, and reverse them
 * - try to search for substring from both ends (forward and backward) at the same loop iteration
 * results: timeout
 */
class Solution3 {
public:
    string longestPalindrome(string s) {
        vector<string> suffixes;
        int max = 0;
        int n = s.size();
        string ss1, ss2, rss1, rss2, result = "";

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-i; ++j) {
                // create forward substring (remove char from the begining)
                ss1 = s.substr(i, n-j-i);
                // create backward substring ()
                ss2 = s.substr(i+j, n);
                if (max < n-j-i) {
                    rss1 = ss1;
                    reverse(rss1.begin(), rss1.end());
                    if (ss1 == rss1) {
                        result = ss1;
                        max = result.size();
                    } else {
                        rss2 = ss2;
                        reverse(rss2.begin(), rss2.end());
                        if (ss2 == rss2) {
                            result = ss2;
                            max = result.size();
                        }
                    }
                }
            }
        }
        return result;
    }
};

/**
 * SOLUTION 4:
 * Brute Force O(n^2)
 * - keep checking substrings from both sides
 * - remove all std calls like reverse method
 * results: timeout
 */
class Solution4 {
public:
    string longestPalindrome(string s) {
        vector<string> suffixes;
        int max = 0;
        int n = s.size();
        string result = "";
        int offset = 0;

        for (auto it_i = s.begin(); it_i < s.end(); ++it_i) {
            auto it_rj = s.rbegin() + offset;
            string ss1, ss2, rss1, rss2 = "";
            int j = 0;
            for (auto it_j = s.begin(); it_j < s.end() - offset; ++it_j) {
                ss1 += *it_j;
                rss1 = *it_j + rss1;
                ss2 += *it_rj;
                rss2 = *it_rj + rss2;
                if (max < j) {
                    if (ss1 == rss1) {
                        max = j;
                        result = ss1;
                    } else if (ss2 == rss2) {
                        max = j;
                        result = ss2;
                    }
                } 
                ++it_rj;
                ++j;
            }
            ++offset;
        }
        return result;
    }
};


/**
 * SOLUTION 5:
 * Brute Force O(n^2)
 * - keep checking substrings from both sides
 * - start from the longest possible substrings, remove chars during iteration
 * results: timeout
 */
class Solution5 {
public:
    string longestPalindrome(string s) {
        vector<string> suffixes;
        int max = 0;
        int n = s.size();
        string result = "";
        int offset = 0;

        string forward_str = s;
        string backward_str = s;

        while(!s.empty()) {
            string forward_str = s;
            string backward_str = s;
            if (s.size() <= result.size()) {
                return result;
            }
            while (!forward_str.empty()) {
                cout << "forward: " << forward_str << "\n";
                string rforward_str = forward_str;
                reverse(rforward_str.begin(), rforward_str.end());
                
                cout << "backward: " << backward_str << "\n";
                string rbackward_str = backward_str;
                reverse(rbackward_str.begin(), rbackward_str.end());

                if (max < forward_str.size()) {
                    if (forward_str == rforward_str) {
                        max = forward_str.size();
                        result = forward_str;
                    } else if (backward_str == rbackward_str) {
                        result = backward_str;
                    }
                }
                forward_str.erase(forward_str.begin());
                backward_str.pop_back();
            }
            s.pop_back();
        }
        return result;
    }
};

#include <unordered_map>

/**
 * SOLUTION 6:
 * Manacher algorithm (1975) O(n)
 * results: 
 * runtime: 32ms, beats 57.94%
 * memory: 42.85MB, beats 29.93%
 */
class Solution {
public:
    string longestPalindrome(string s) {
        // Verify if we are not dealing with palindrome from the early beginning
        // This step is not neccessary but it can speed up execution.
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (s == rs) {
            return s;
        }
        // Enrich input string to create S' argument
        ostringstream eoss;
        eoss << '|';
        for (char sign : s) {
            eoss << sign;
            eoss << '|';
        }
        string es = eoss.str();
        // start Manacher algorithm
        unordered_map <int, pair<int, string>> palindrome_radii = { };
        int center = 0;
        int radius = 0;
        int es_length = es.length();
        string result = { es[center] };

        while (center < es_length) {
            // At the start of the loop, Radius is already set to a lower-bound
            // for the longest radius. In the first iteration, Radius is 0, but
            // it can be higher on later iterations.
            // Determine the longest palindrome starting at Center-Radius and
            // going to Center+Radius
            while ((center - (radius + 1)) >= 0 && 
                   (center + (radius + 1)) < es_length &&
                   es[center - (radius + 1)] == es[center + (radius + 1)]) {
                result = es[center - (radius + 1)] + result + es[center + (radius + 1)];
                ++radius;
            }
            // Save the radius of the longest palindrome in the vector
            palindrome_radii[center].first = radius;
            palindrome_radii[center].second = result;
            // Below, center is incremented.
            // If any precomputed values can be reused, they are.
            // Also, Radius may be set to a value greater than 0
            int old_center = center;
            int old_radius = radius;
            //cout << "center: " << center << " result: " << result << "\n";
            ++center;
            // Radius' default value will be 0, if we reach the end of the
            // following loop. 
            radius = 0;
            result = es.substr(center, 1);
            
            while (center <= old_center + old_radius) {
                // Because Center lies inside the old palindrome and every
                // character inside a palindrome has a "mirrored" character
                // reflected across its center, we can use the data that was
                // precomputed for the Center's mirrored point. 
                int mirrored_center = old_center - (center - old_center);
                int max_mirrored_radius = old_center + old_radius - center;
                if (palindrome_radii[mirrored_center].first < max_mirrored_radius) {
                    // The palindrome centered at mirrored_center is entirely
                    // contained in the palindrome centered at old_center So,
                    // mirrored_center and center have the same sized palindrome
                    palindrome_radii[center].first = palindrome_radii[mirrored_center].first;
                    palindrome_radii[center].second = palindrome_radii[mirrored_center].second;
                    ++center;
                } else { // palindrome_radii[mirrored_center].first == max_mirrored_radius
                    // Since the palindrome at mirrored_center ends exactly at
                    // the edge of the palindrome centered at old_center, the
                    // palindrome at center might be bigger. Set radius to the
                    // minimum size of the palindrome at center so it doesn't
                    // recheck unnecessarily
                    radius = max_mirrored_radius;
                    // we need to copy previous palindome, we have to copy everything
                    // before and after the center which the length of radius,
                    // we also have to add +1 for the center char.
                    result = es.substr(center - radius, (2 * radius) + 1);
                    break;
                }
            }
        }

        // A palindrome's size is equal to its radius * 2. However, since our
        // variable Radius considers our bogus characters ("|") to the side of the
        // center, the size of its corresponding palindrome is actually 2 *
        // (Radius / 2), which means a palindrome's size is equal to its
        // corresponding radius value in palindrome_radii
        auto m_it = max_element(
            palindrome_radii.begin(),
            palindrome_radii.end(),
            [](const auto& a, const auto& b) { return a.second.first < b.second.first; }
        );

        // remove markup character from the result
        m_it->second.second.erase(remove(m_it->second.second.begin(), m_it->second.second.end(), '|'), m_it->second.second.end());
        return m_it->second.second;
    }
};


int main() {
    // testcase1
    string test1 = "babadada";
    string test2 = "caaaaa";
    string test3 = "aaaa";

    Solution s;
    cout << s.longestPalindrome(test3) << "\n";
    return 0;
}