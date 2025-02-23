/**
 * PROBLEM DESCRIPTION
 * 2342. Max Sum of a Pair With Equal Sum of Digits
 * 
 * You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j,
 * and the sum of digits of the number nums[i] is equal to that of nums[j].
 * Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
 * 
 * Example 1:
 * Input: nums = [18,43,36,13,7]
 * Output: 54
 * Explanation: The pairs (i, j) that satisfy the conditions are:
 * - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
 * - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
 * So the maximum sum that we can obtain is 54.
 * 
 * Example 2:
 * Input: nums = [10,12,19,14]
 * Output: -1
 * Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 */

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

/**
 * SOLUTION 1:
 * First solution, the most primitive approach
 * results:
 * runtime: 48ms, beats 28.42%
 * memory: 63.90MB, beats 17.63%
 */
class Solution {
private:
    // The most popular method to mark private mthods in C++ is to add underscore at the end of the name
    // It's used by Google (follows Google Style), LLVM, Qt... 
    int addDigits_(int num) {
        int sum =  num % 10;
        if (num < 10) {
            return num;
        }
        // bellow casting method is C-like, it's not recommended in modern C++
        // sum += addDigits((int)(num / 10));
        // because:
        // - types are not controlled, so you can also cast value to pointer and vice-versa
        // - inheritance is not check for objects at runtime so you can cast Parent object to child object by accident
        // - can't cast const value to regular type and change its value by accident
        // recommended casting methods are:
        // - static_cast<>: between compatible types (safe) 
        // - dynamic_cast<>: casting in order to inheritance (checked in runtime), in a case of erro nullptr will be returned
        // - const_cast<>: casting dedicated for const values
        // - reinterpreted_cast<>: pointer casting to types that may not be related (unsafe)
        sum += addDigits_(static_cast<int>(num / 10));
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> match_holder;
        // usage of "range loop for", it is recommended way to do it
        for (int num : nums) {
            int digits_sum = addDigits_(num);
            match_holder[digits_sum].push_back(num);
        }
        // it's the same as:
        // for (auto num = nums.begin(); num != nums.end(); ++num) {
        //     int digits_sum = addDigits(*num);
        //     match_holder[digits_sum].push_back(*num);
        // }
        int result = -1;
        // pass reference to avoid copying
        for (auto& match : match_holder) {
            // sort function takes reference, so it will sort the original vector not a copy (page 23)
            // if we don't want to modify original object, but still want to avoid cvalue copy, const reference can be passed
            sort(match.second.begin(), match.second.end(), greater<int>());
            if (match.second.size() > 1) {
                result = result < (match.second[0] + match.second[1]) ? match.second[0] + match.second[1] : result;    
            }
            // cout << "[" << match.first << "] = {";
            // for (int classified_num : match.second) {
            //     cout << classified_num << ", ";
            // }
            // cout << "} \n";
        }
        return result;
    }
};

/**
 * SOLUTION 2 [BEST]
 * - there is no reasone to keep all of the numbers which digits sum gives us the same value
 * results:
 * runtime: 30ms, beats 49.85%
 * memory: 63.90MB, beats 75.53%
 */
 template<typename K, typename V>
 class InitializedMap : public map<K, V> {
 private:
     V default_value;
 public:
     InitializedMap<K, V>(V default_value) : default_value(default_value) { }
     V& operator[](const K& key) {
         return map<K, V>::try_emplace(key, default_value).first->second;
     }
 };

class Solution2 {
private:
    int addDigits_(int num) {
        int sum =  num % 10;
        if (num < 10) {
            return num;
        }
        sum += addDigits_(static_cast<int>(num / 10));
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        // lack of explicite declaration, it's not the best idea for data that is allocated in stack
        // template classes will use predefined constructor, for argument types, however it does not exists
        // for base types (POD - Plain Old Data), but may exist for other objects.
        // we have to follow RAII rule and initialize data, in this case when we are trying to access
        // key which does not exist yet, the default default constructor of map class will be used,
        // and pair will be initialize with "0" values because it's an aggregate type.
        map<int, pair<int, int>> match_holder;
        // however it can be changed, by try_emplace method:
        // for C++17 and higher: - the existence of the key can be checked and default value can be changed by try_emplace method
        // however you have to define lambda expression to access elements or inherit from the map class or overwrite contructor
        // APPROACH 1:
        // lambda: [object - can be empty](arguments) -> type_of_returned_value { return ... };
        //   try_emplace will return pair<map<K, V>::iterator, bool>
        //   .first gives map<K, V>:: iterator which point to the pair<key, value>
        //   ->second gives value from the pair pointed by iterator
        // auto getElement = [&match_holder](int key) -> pair<int, int>& {
        //     return match_holder.try_emplace(key, 1, 1).first->second;
        // };
        // for (int num : nums) {
        //     int digits_sum = addDigits_(num);
        //     cout << "[0]: " << getElement(digits_sum).first << " [1]: " << getElement(digits_sum).second << "\n";
        // }
        // cout << "\n";
        // APPROACH 2:
        // or overload constructor of map class to do it we have to define our own type which will inherit from the standard type
        // InitializedMap<int, pair<int, int>> match_holder_ext({2, 2});
        // for (int num : nums) {
        //     int digits_sum = addDigits_(num);
        //     cout << "[0]: " << match_holder_ext[digits_sum].first << " [1]: " << match_holder_ext[digits_sum].second << "\n";
        // }
        // cout << "\n";

        for (int num : nums) {
            int digits_sum = addDigits_(num);
            if (match_holder[digits_sum].first < num) {
                match_holder[digits_sum].second = match_holder[digits_sum].first;
                match_holder[digits_sum].first = num;
            } else if (match_holder[digits_sum].second < num) {
                match_holder[digits_sum].second = num;
            }
        }

        int result = -1;
        for (auto& match : match_holder) {
            if (match.second.second != 0) {
                result = result < (match.second.first + match.second.second) ? match.second.second + match.second.first : result;    
            } 
        }
        return result;
    }
};

/**
 * SOLUTION 3
 * - there is no reasone to keep all of the numbers which digits sum gives us the same value
 * results:
 * runtime: 43ms, beats 34.35%
 * memory: 63.82MB, beats 75.53%
 */
class Solution3 {
private:
    int addDigits_(int num) {
        int sum =  num % 10;
        if (num < 10) {
            return num;
        }
        sum += addDigits_(static_cast<int>(num / 10));
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int result = -1;
        map<int, int> match_holder;
        for (int num : nums) {
            int digits_sum = addDigits_(num);
            if (match_holder[digits_sum] != 0) {
                if (result < (num + match_holder[digits_sum])) {
                    result = num + match_holder[digits_sum];
                }
            } else {
                match_holder[digits_sum] = num;
            }
            if (match_holder[digits_sum] < num) {
                match_holder[digits_sum] = num;
            } 
        }
        return result;
    }
};

int main() {
    vector<int> data0 { 18, 43, 36, 13, 7 };
    vector<int> data1 { 10, 12, 19, 14 } ;
    vector<int> data2 { 229,398,269,317,420,464,491,218,439,153,482,169,411,93,147,50,347,210,251,366,401 };
    vector<int> data3 { 823703329,480039933,809171582,932997750,273044544,169377999,934873215,233647188,158618699,202520394,68072925,125681501,670651183,230820178,915758279,752568096,296064268,151228344,375377293,209059107,448933132,818820630,110175008,806565076,739731036,489874660,282855112,47714602,584068185,891589173,876914517,580918354,479971782,449499425,216865394,854065554,82508309,382132812,894006664,305065615,387620257,816387629,665212188,126543967,879206027,904333398,728770713,658820347,503837967,638662017,281639650,133495536,144456727,538669949,966915953,593517802,668414263,928153417,318735728,629384449,48746121,151760257,514192873,148335554,963367452,464392190,763425250,281001523,363726765,207303869,768796407,317099854,418615735,353528229,552853579,536131170,299553121,321258134,969494602,974060371,915287366 };
    Solution3 s;
    int result = s.maximumSum(data3);
    cout << result << "\n";
    return 0;
}