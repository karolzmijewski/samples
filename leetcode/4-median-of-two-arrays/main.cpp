/**
 * PROBLEM DESCRIPTION
 * 4. Median of Two Sorted Arrays
 * 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 */


#include <vector>
#include <iostream>

using namespace std;

/**
 * SOLUTION 1:
 * results:
 * runtime: 1ms, beats 43.14%
 * memory: 96.18MB, beats 11.12%
 */
class Solution1 {
public:
    vector<int>* merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* result = new vector<int>();
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        int max_size = nums1.size() + nums2.size();

        for (int it = 0; it < max_size; ++it) {
            if (it1 == nums1.end()) {
                cout << "nums2: merge rest \n";
                result->insert(result->end(), it2, nums2.end());
                return result;
            }
            if (it2 == nums2.end()) {
                cout << "nums1: merge rest \n";
                result->insert(result->end(), it1, nums1.end());
                return result;
            }
            if (*it1 <= *it2) {
                cout << "nums1: Push " << *it1 << "\n";
                result->push_back(*it1);
                ++it1;
            } else {
                cout << "nums2: Push " << *it2 << "\n";
                result->push_back(*it2);
                ++it2;
            }
        }
        return result;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* merged_vec = merge(nums1, nums2);
        double result = 0.0;
        
        cout << "{ ";
        for (int n : *merged_vec) {
            cout << n << ", ";
        }
        cout << " }\n";

        int r_size = merged_vec->size();

        if ((r_size % 2) == 0) {
            double a = static_cast<double>((*merged_vec)[(r_size / 2) - 1]);
            double b = static_cast<double>((*merged_vec)[(r_size / 2)]);
            result = (a + b) / 2.0;
        } else {
            result = static_cast<double>((*merged_vec)[r_size / 2]);
        }

        merged_vec->clear();
        delete(merged_vec);

        cout << "result: " << result << "\n";
        return result;
    }
};

/**
 * SOLUTION 2:
 * Starting from C++11 it's using RVO (Return Value Optimization), it ensures that returned vector
 * resources will be moved to the result variable by default. So there is no need to move it manually,
 * or declare pointer to the resources allocated in memory heap.
 * results:
 * runtime: 0ms, beats 100.00%
 * memory: 96.18MB, beats 11.12%
 */
class Solution2 {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result {};
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        int max_size = nums1.size() + nums2.size();

        for (int it = 0; it < max_size; ++it) {
            if (it1 == nums1.end()) {
                result.insert(result.end(), it2, nums2.end());
                return result;
            }
            if (it2 == nums2.end()) {
                result.insert(result.end(), it1, nums1.end());
                return result;
            }
            if (*it1 <= *it2) {
                result.push_back(*it1);
                ++it1;
            } else {
                result.push_back(*it2);
                ++it2;
            }
        }
        return result;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged_vec = merge(nums1, nums2);
        double result = 0.0;
        int r_size = merged_vec.size();

        if ((r_size % 2) == 0) {
            double a = static_cast<double>(merged_vec[(r_size / 2) - 1]);
            double b = static_cast<double>(merged_vec[(r_size / 2)]);
            result = (a + b) / 2.0;
        } else {
            result = static_cast<double>(merged_vec[r_size / 2]);
        }

        return result;
    }
};


int main() {
    // testcase1
    vector<int> nums1 { 1, 3 };
    vector<int> nums2 { 2 };

    Solution2 s;
    s.findMedianSortedArrays(nums1, nums2); 
    return 0;
}