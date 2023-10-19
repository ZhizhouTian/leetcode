/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.39%)
 * Likes:    1439
 * Dislikes: 0
 * Total Accepted:    387.7K
 * Total Submissions: 784.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
    bool _spiralOrder(vector<vector<int>>& matrix, vector<int>& result, int left, int right, int top, int bottom) {
        if (left > right) return false;
        if (top > bottom) return false;

        if (left == right && top == bottom) {
            result.push_back(matrix[left][top]);
            return false;
        }

        if (left == right) {
            for (int i=top; i<=bottom; i++)
                result.push_back(matrix[i][left]);
            return false;
        }

        if (top == bottom) {
            for (int i=left; i<=right; i++)
                result.push_back(matrix[top][i]);
            return false;
        }

        for (int i=left; i<=right; i++)
            result.push_back(matrix[top][i]);
        for (int i=top+1; i<=bottom; i++)
            result.push_back(matrix[i][right]);
        for (int i=right-1; i>=left; i--)
            result.push_back(matrix[bottom][i]);
        for (int i=bottom-1; i>=top+1; i--)
            result.push_back(matrix[i][left]);
        return true;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int left=0, right=matrix[0].size()-1, top=0, bottom=matrix.size()-1;
        while (true) {
            if (!_spiralOrder(matrix, result, left, right, top, bottom))
                break;
            left++;
            right--;
            top++;
            bottom--;
        }

        return result;
    }
};
// @lc code=end

int main(void) {
    //vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int>> matrix = {{3}, {2}};

    Solution s;
    s.spiralOrder(matrix);
}