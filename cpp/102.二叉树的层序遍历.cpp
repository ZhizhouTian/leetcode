/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (65.63%)
 * Likes:    1714
 * Dislikes: 0
 * Total Accepted:    828.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;

        vector<TreeNode*> levelNodeVector;
        levelNodeVector.push_back(root);
        res.push_back({root->val});
        int current = 0;
        int size = 1;

        while (true) {
            int levelCount = 0;
            vector<int> levelValueVector;
            while (current < size) {
                TreeNode* n = levelNodeVector[current];
                if (n->left) {
                    levelValueVector.push_back(n->left->val);
                    levelNodeVector.push_back(n->left);
                    levelCount++;
                }
                if (n->right) {
                    levelValueVector.push_back(n->right->val);
                    levelNodeVector.push_back(n->right);
                    levelCount++;
                }
                current++;
            }
            if (levelCount == 0)
                break;
            size += levelCount;
            res.push_back(levelValueVector);
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        res.push_back({root->val});

        int size = 1;

        while (true) {
            vector<int> levelValues;

            for (int i = 0; i < size; i++) {
                TreeNode *n = nodeQueue.front();
                nodeQueue.pop();
                if (n->left) {
                    levelValues.push_back(n->left->val);
                    nodeQueue.push(n->left);
                }

                if (n->right) {
                    levelValues.push_back(n->right->val);
                    nodeQueue.push(n->right);
                }

            }
            if (nodeQueue.empty())
                break;
            size = nodeQueue.size();
            res.push_back(levelValues);
        }

        return res;
    }
};
// @lc code=end

