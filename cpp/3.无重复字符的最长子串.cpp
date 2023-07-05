/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.11%)
 * Likes:    9289
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 6.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)  return 0;

        vector<int> dp(s.size());
        dp[0] = 1;

        for (int i=1; i<s.size(); i++) {
            int cnt = 1;
            for (int j=i-1; j>=i-dp[i-1]; j--) {
                if (s[i] == s[j])
                    break;
                cnt++;
            }
            dp[i] = cnt;
        }

        int maxVal = 0;
        for (int i=0; i<dp.size(); i++)
            maxVal = max(maxVal, dp[i]);
        return maxVal;
    }
};
// @lc code=end

