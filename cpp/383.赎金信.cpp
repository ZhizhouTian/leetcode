/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (60.71%)
 * Likes:    757
 * Dislikes: 0
 * Total Accepted:    357.2K
 * Total Submissions: 587.7K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 
 * 如果可以，返回 true ；否则返回 false 。
 * 
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
 * 
 * 
 */

#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r[256], m[256];

        memset(r, 0, sizeof(int) * 256);
        memset(m, 0, sizeof(int) * 256);
        for (auto& c: ransomNote)
            r[c]++;
        for (auto& c: magazine)
            m[c]++;
        for (int i=0; i<256; i++) {
            if (r[i] > m[i]) return false;
        }
        return true;
    }
};
// @lc code=end

int main(void) {
    Solution s;

    cout << s.canConstruct("aa", "aab") << endl;
    return 0;
}