/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.82%)
 * Likes:    1568
 * Dislikes: 0
 * Total Accepted:    496.7K
 * Total Submissions: 732K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */

#include <vector>
#include <string>
#include <map>

using namespace std;

// @lc code=start
class Solution {
    int findBitmap(vector<vector<int>>& bitmap, vector<int>& bm) {
        for (int i=0; i<bitmap.size(); i++) {
            int equal = true;
            for (int j=0; j<26; j++) {
                if (bitmap[i][j] != bm[j]) {
                    equal = false;
                    break;
                }
            }
            if (equal)
                return i;
        }
        return -1;
    }

    vector<int> getStrBitmap(string& str) {
        vector<int> bitmap(26, 0);
        for (auto c: str)
            bitmap[c-'a']++;
        return bitmap;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<vector<int>> bitmap(0, vector<int>(26,0));

        for (auto& str: strs) {
            vector<int> strbm = getStrBitmap(str);
            int index = findBitmap(bitmap, strbm);
            if (index == -1) {
                bitmap.push_back(strbm);
                vector<string> newAnagrams;
                newAnagrams.push_back(str);
                result.push_back(newAnagrams);
                continue;
            }
            result[index].push_back(str);
        }
        return result;
    }
};
// @lc code=end

int main(void) {
    Solution s;
    vector<string> testcase1 = {"aab", "ab", "ba"};
    s.groupAnagrams(testcase1);
    return 0;
}