/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.60%)
 * Likes:    6593
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int ret = 0;
        int index = 0;
        for (int i=0; i<s.size(); i++) {
            int j=1;
            while (i-j>=0 && i+j<s.size()) {
                if (s[i-j] != s[i+j])
                    break;
                j++;
            }

            if (j>ret) {
                ret = j;
                index = i;
            }
        }

        bool internal = false;
        for (int i=0; i<s.size()-1; i++) {
            int j=0;
            while (i-j>=0 && i+j+1<s.size()) {
                if (s[i-j] != s[i+j+1])
                    break;
                j++;
            }

            if (j>ret) {
                ret = j;
                index = i;
                internal = true;
            }
        }

        if (!internal)
            return s.substr(ret-index, 1+2*ret);
        return s.substr(ret-index, 2*ret);
    }
};
// @lc code=end

int main(void) {

}