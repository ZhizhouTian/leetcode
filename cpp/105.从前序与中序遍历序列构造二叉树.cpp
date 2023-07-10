/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.28%)
 * Likes:    2009
 * Dislikes: 0
 * Total Accepted:    507.3K
 * Total Submissions: 711.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
 * 
 * 
 */

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

#include <map>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    void getIndexMap(vector<int>& order, map<int, int>& omap) {
        for (int i=0; i<order.size(); i++) {
            omap[order[i]] = i;
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || !inorder.size()) return nullptr;
        if (preorder.size() != inorder.size()) return nullptr;

        map<int, int> omap, pmap;
        getIndexMap(inorder, omap);
        getIndexMap(preorder, pmap);

        TreeNode* root = new TreeNode(preorder[0]);
        vector<TreeNode*> nv;
        nv.push_back(root);
        int start=0, end=nv.size();

        while (true) {
            bool hasNewNode = false;
            for (; start<end; start++) {
                TreeNode* n = nv[start];
                int index = pmap[n->val];
                // check left
                if (index+1<preorder.size()) {
                    int left = preorder[index+1];
                    if (omap[left] < omap[n->val]) {
                        n->left = new TreeNode(left);
                        nv.push_back(n->left);
                        hasNewNode = true;
                    }
                }
                // check right
                if (index+2<preorder.size()) {
                    int right = preorder[index+2];
                    if (omap[right] > omap[n->val]) {
                        n->right = new TreeNode(right);
                        nv.push_back(n->right);
                        hasNewNode = true;
                    }
                }
            }
            if (!hasNewNode) break;
            end = nv.size();
        }

        return root;
    }
};
// @lc code=end

int main(void) {
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    s.buildTree(preorder, inorder);
}