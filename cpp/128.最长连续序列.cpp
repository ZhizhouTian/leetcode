/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.59%)
 * Likes:    1757
 * Dislikes: 0
 * Total Accepted:    421.9K
 * Total Submissions: 775.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        sort(nums.begin(), nums.end());

        int max = 1;
        vector<int> dp(nums.size(), 1);

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                dp[i] = dp[i-1];
                continue;
            }

            if (nums[i] == nums[i-1] + 1) {
                dp[i] = dp[i-1]+1;
                if (dp[i] > max)
                    max = dp[i];
            }
        }

        return max;
    }
};
// @lc code=end

int main(void) {
    Solution s;
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << s.longestConsecutive(nums) << endl;
}
