/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (49.37%)
 * Likes:    1982
 * Dislikes: 0
 * Total Accepted:    671K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
    static bool intervalGreater(const vector<int>& va, const vector<int>& vb) {
        return va[0] < vb[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), intervalGreater);

        result.push_back(intervals[0]);
        int index = 0;
        for (int i=1; i<intervals.size(); i++) {
            if (result[index][1] >= intervals[i][0]) {
                result[index][1] = max(intervals[i][1], result[index][1]);
                continue;
            }
            result.push_back(intervals[i]);
            index++;
        }
        return result;
    }
};
// @lc code=end

int main(void) {
    Solution s;
    vector<vector<int>> intervals = {{2, 6}, {1, 3}};
    s.merge(intervals);
    return 0;
}