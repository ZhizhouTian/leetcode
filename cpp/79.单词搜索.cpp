/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode.cn/problems/word-search/description/
 *
 * algorithms
 * Medium (46.26%)
 * Likes:    1621
 * Dislikes: 0
 * Total Accepted:    434.8K
 * Total Submissions: 939.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool __exist(vector<vector<char>>& board, string& word, int i, int j, vector<vector<int>>& path, int k) {
        if (k >= word.size())
            return true;

        for (int index=0; index<k; index++) {
            if (path[index][0] == i && path[index][1] == j)
                return false;
        }

        if (word[k] != board[i][j])
            return false;

        if (k+1 >= word.size())
            return true;

        bool result = false;
        path[k] = {i, j};

        // left
        if (j >= 1)
            result |= __exist(board, word, i, j-1, path, k+1);

        // up
        if (i >= 1)
            result |= __exist(board, word, i-1, j, path, k+1);

        // right
        if (j < board[0].size() - 1)
            result |= __exist(board, word, i, j+1, path, k+1);

        // down
        if (i < board.size() - 1)
            result |= __exist(board, word, i+1, j, path, k+1);

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> path(word.size());
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                bool e = __exist(board, word, i, j, path, 0);
                if (e)
                    return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main(void)
{
    Solution s;
    vector<vector<char>> v = {{'a', 'b', 'c', 'e'}};

    cout << s.exist(v, "abcb") << endl;
    return 0;
}