/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode.cn/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (63.20%)
 * Likes:    996
 * Dislikes: 0
 * Total Accepted:    351.8K
 * Total Submissions: 556.6K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点总数在范围 [0, 5000] 内
 * -1000 
 * -1000 
 * 
 * 
 * 
 * 
 */

/**
 * Definition for a binary tree node.
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    void walk(TreeNode* root, vector<vector<int>>& result, vector<int>& path, int depth, int currentSum, int targetSum) {
        if (!root)  return;
        if (!root->left && !root->right) {
            currentSum += root->val;
            path[depth] = root->val;
            if (currentSum == targetSum) {
                vector<int> v(path.begin(), path.begin()+depth+1);
                result.push_back(v);
            }
            return;
        }

        path[depth] = root->val;
        if (root->left)
            walk(root->left, result, path, depth+1, currentSum+root->val, targetSum);

        if (root->right)
            walk(root->right, result, path, depth+1, currentSum+root->val, targetSum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path(5000);

        walk(root, result, path, 0, 0, targetSum);
        return result;
    }
};
// @lc code=end

