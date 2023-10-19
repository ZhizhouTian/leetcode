/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.85%)
 * Likes:    823
 * Dislikes: 0
 * Total Accepted:    636.6K
 * Total Submissions: 966.3K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
class Solution {
    vector<int> getBitmap(string& str) {
        vector<int> bitmap(26, 0);
        for (auto& c: str)
            bitmap[c-'a']++;
        return bitmap;
    }
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> sBitmap = getBitmap(s);
        vector<int> tBitmap = getBitmap(t);

        for (int i=0; i<sBitmap.size(); i++) {
            if (sBitmap[i] != tBitmap[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

