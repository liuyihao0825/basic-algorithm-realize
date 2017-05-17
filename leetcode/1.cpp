// Question:
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Case:
// Given nums = [2, 7, 11, 15], target = 9
// return [0, 1]

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

// solution 1: brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 0;

        int index1;
        int index2;

        bool flag = false;

        vector<int>::iterator it = nums.begin();
        for (; it != nums.end(); ++it) {
            i = *it;
            vector<int>::iterator it2 = it + 1;
            for (; it2 != nums.end(); ++it2) {
                j = *it2;

                if (i + j == target) {
                    flag = true;
                    index2 = it2 - nums.begin();
                    break;
                }
            }

            if (true == flag) {
                index1 = it - nums.begin();
                break;
            }
        }

        vector<int> res;
        if (true == flag) {
            res.push_back(index1);
            res.push_back(index2);
        } else {
        }

        return res;
    }
};

// solution 2: use hash_map two-pass, k=>num, v=>index
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	// TODO: imeplate
	return vector<int>();
    }
};

// solution 3: use hash_map one-pass, k=>num, v=>index
// 插入数据时，check之前的数据中，是否存在满足条件的数据，减少插入次数
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	// TODO: imeplate
	return vector<int>();
    }
};

// TEST CASE
int main(int argc, char** argv) {
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(11);
    vec.push_back(7);
    vec.push_back(15);

    int target = 9;

    Solution st;
    vector<int> res;
    res = st.twoSum(vec, target);

    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
