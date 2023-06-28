/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (58.82%)
 * Likes:    2453
 * Dislikes: 0
 * Total Accepted:    846.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 * 
 */

#include <iostream>
#include <list>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

// @lc code=start
class Solution {
public:
    bool __isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)    return true;
        if (left && !right) return false;
        if (!left && right) return false;
        if (left->val != right->val)  return false;
        return __isSymmetric(left->left, right->right) && __isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return __isSymmetric(root->left, root->right);
    }
};
// @lc code=end
