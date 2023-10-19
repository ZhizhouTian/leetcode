/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode.cn/problems/word-pattern/description/
 *
 * algorithms
 * Easy (44.62%)
 * Likes:    588
 * Dislikes: 0
 * Total Accepted:    137.7K
 * Total Submissions: 308.6K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 
 * 
 * 示例1:
 * 
 * 
 * 输入: pattern = "abba", s = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 
 * 输入:pattern = "abba", s = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 
 * 输入: pattern = "aaaa", s = "dog cat cat dog"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= pattern.length <= 300
 * pattern 只包含小写英文字母
 * 1 <= s.length <= 3000
 * s 只包含小写英文字母和 ' '
 * s 不包含 任何前导或尾随对空格
 * s 中每个单词都被 单个空格 分隔
 * 
 * 
 */

#include <vector>
#include <string>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> getSplit(string s, char *delim) {
        vector<string> result;
        char *split = strtok((char*)s.c_str(), " ");
        while (split) {
            result.push_back(string(split));
            split = strtok(NULL, " ");
        }
        return result;
    }

    bool wordPattern(string pattern, string s) {
        vector<string> splits = getSplit(s, " ");
        map<char, string> m1;
        map<string, char> m2;

        if (pattern.size() != splits.size()) return false;
        for (int i=0; i<pattern.size(); i++) {
            if (m1.count(pattern[i]) && m1[pattern[i]]!=splits[i]) return false;
            if (m2.count(splits[i]) && m2[splits[i]]!=pattern[i]) return false;
            m1[pattern[i]] = splits[i];
            m2[splits[i]] = pattern[i];
        }

        return true;
    }
};
// @lc code=end

int main(void) {
    string s = "dog cat cat dog";
    string item;
    vector<string> v;
    char *c_s = (char*)s.c_str();

    char *split = strtok(c_s, " ");
    while (split != NULL) {
        v.push_back(string(split));
        split = strtok(NULL, " ");
    }
    return 0;
}