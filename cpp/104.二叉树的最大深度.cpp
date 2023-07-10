/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (77.13%)
 * Likes:    1635
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
 * 
 */

#include <vector>

using namespace std;

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

// @lc code=start
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int start = 0, end = nodes.size();
        int level = 1;

        while (true) {
            bool hasNode = false;
            for (; start<end; start++) {
                if (nodes[start]->left) {
                    nodes.push_back(nodes[start]->left);
                    hasNode = true;
                }
                if (nodes[start]->right) {
                    nodes.push_back(nodes[start]->right);
                    hasNode = true;
                }
            }
            if (!hasNode)
                break;
            level++;
            end = nodes.size();
        }

        return level;
    }
};
// @lc code=end

