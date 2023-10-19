/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 *
 * https://leetcode.cn/problems/game-of-life/description/
 *
 * algorithms
 * Medium (75.77%)
 * Likes:    516
 * Dislikes: 0
 * Total Accepted:    79.3K
 * Total Submissions: 104.7K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * 根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
 * 
 * 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为
 * 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
 * 
 * 
 * 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
 * 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
 * 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 * 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
 * 
 * 
 * 下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board
 * 的当前状态，返回下一个状态。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
 * 输出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [[1,1],[1,0]]
 * 输出：[[1,1],[1,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 25
 * board[i][j] 为 0 或 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
 * 本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
 * 
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
    int neighboorCount(vector<vector<int>>& board, int i, int j) {
        int sum = 0;
        if (i>=1 && j>=1) sum += board[i-1][j-1];
        if (i>=1) sum += board[i-1][j];
        if (i>=1 && j<board[0].size()-1) sum += board[i-1][j+1];
        if (j>=1) sum += board[i][j-1];
        if (j<board[0].size()-1) sum += board[i][j+1];
        if (i<board.size()-1 && j>=1) sum += board[i+1][j-1];
        if (i<board.size()-1) sum += board[i+1][j];
        if (i<board.size()-1 && j<board[0].size()-1) sum += board[i+1][j+1];

        return sum;
    }
    int survive(vector<vector<int>>& board, int i, int j) {
        int cnt = neighboorCount(board, i, j);
        if (board[i][j] == 1) {
            if (cnt < 2) return 0;
            if (cnt > 3) return 0;
            if (cnt == 2 || cnt == 3) return 1;
        } else if (board[i][j] == 0){
            if (cnt == 3) return 1;
        } else {
            cout << "waring" << endl;
        }
        return 0;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> result(board.size(), vector<int>(board[0].size()));
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                result[i][j] = survive(board, i, j);
            }
        }

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                board[i][j] = result[i][j];
            }
        }
    }
};
// @lc code=end

