/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.51%)
 * Likes:    6585
 * Dislikes: 0
 * Total Accepted:    959.9K
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    /* 中位数的定义：将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。*/
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 < *it2) {
                merged.push_back(*it1);
                it1++;
            } else {
                merged.push_back(*it2);
                it2++;
            }
        }
        for (; it1 != nums1.end(); it1++) {
            merged.push_back(*it1);
        }
        for (; it2 != nums2.end(); it2++) {
            merged.push_back(*it2);
        }

        int mid = merged.size() / 2;
        if (merged.size() % 2 == 1)
            return merged[mid];
        else
            return float((merged[mid] + merged[mid-1])) / 2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* 1. merge two vector with order*/
        vector<int> v(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        
        /* 2. get mid of vector */
        int size = v.size();
        if ((size % 2 ) == 0)
            return float(v[size / 2] + v[size/2 - 1]) / 2;
        return v[size / 2];
    }
};

// @lc code=end

