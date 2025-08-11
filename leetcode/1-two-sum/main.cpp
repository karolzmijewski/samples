/**
 * PROBLEM DESCRIPTION
 * 1. Two Sum
 * 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * SOLUTION 1:
 * First solution, the most primitive approach
 * results:
 * runtime: 137ms, beats 6.03%
 * memory: 261.33MB, beats 7.22%
 */
class Solution1 {
public:
    int c = 0;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result { -1, -1 };
        int index = 0;
        int search_num = 0;
        bool flag = false;
        for (int num : nums) {
            cout << "Proceess: " << num << "\n";
            if (flag) {
                if (search_num == num) {
                    result[1] = index;
                    cout << "Second: " << num << " id: " << index << "\n";
                    cout << "Return: { " << result[0] << ", " << result[1] << " }\n";
                    return result;
                }
            } else {
                search_num = target - num;
                result[0] = index;
                flag = true;
                cout << "First: " << num << " id: " << index << "\n";
            }
            ++index;
        }
        ++c;
        vector<int> subNums(nums.begin() + result[0] + 1, nums.end());
        vector<int> r = twoSum(subNums, target);
        r[0] += c;
        r[1] += c;
        c = 0;
        return r;
    }
};


/**
 * SOLUTION 2:
 * - there is no need to copy over and over the vector of numbers, it's very inefficient
 * It would be even better to just make loop in loop
 * 
 * results:
 * runtime: 99ms, beats 11.44%
 * memory: 14.14MB, beats 60.42%
 */
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result { -1, -1 };
        bool flag = false;
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << "First [" << i << "] = " << nums[i] << "\n";
            result[0] = i;
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == (target - nums[i])) {
                    cout << "Second [" << j << "] = " << nums[j] << "\n";
                    result[1] = j;
                    return result;
                }
            }
        }
        return result;
    }
};


/**
 * SOLUTION 3:
 * - there is no need to find it in our own, it's beter to use standard library calls
 * 
 * results:
 * runtime: 36ms, beats 38.29%
 * memory: 13.95MB, beats 92.46%
 */
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result { -1, -1 };
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << "First [" << i << "] = " << nums[i] << "\n";
            result[0] = i;
            auto it = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (it != nums.end()) {
                result[1] = distance(nums.begin(), it);
                cout << "Second [" << result[1] << "] = " << nums[result[1]] << "\n";
                return result;
            }
        }
        return result;
    }
};

/**
 * SOLUTION 4:
 * - we can change collection used to hold values to avoid distance count which may be O(n);
 * 
 * results:
 * runtime: 0ms, beats 100%
 * memory: 14.96MB, beats 21.37%
 */
class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i];
            if (result.find(x) != result.end()) {
                return {i, result[x]};
            }
            result[nums[i]] = i;
        }
        return {};
    }
};



int main() {
    // testcase 1
    vector<int> nums0 { 2, 7, 11, 15 };
    int target0 = 9;
    // testcase 2
    vector<int> nums1 { 3, 2, 4 };
    int target1 = 6;
    // testcase 3
    vector<int> nums2 { 3, 3 };
    int target2 = 6;
    // testcase 4
    vector<int> nums3 { 3, 2, 3 };
    int target3 = 6;
    // testcase 5
    vector<int> nums4 { 0, 4, 3, 0 };
    int target4 = 0;
    // testcase 6
    vector<int> nums5 { -1, -2, -3, -4, -5 };
    int target5 = -8;

    Solution4 s;
    vector<int> result = s.twoSum(nums5, target5);
    cout << "{ " << result[0] << ", " << result[1] << " }\n";
    return 0;
}