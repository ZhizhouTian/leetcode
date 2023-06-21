/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode.cn/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (66.04%)
 * Likes:    1148
 * Dislikes: 0
 * Total Accepted:    199.9K
 * Total Submissions: 302.6K
 * Testcase Example:  '[[7,0],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
 * 
 * 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random
 * 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
 * 
 * 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random
 * --> y 。
 * 
 * 返回复制链表的头节点。
 * 
 * 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 * 
 * 
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  0 。
 * 
 * 
 * 你的代码 只 接受原链表的头节点 head 作为传入参数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [[7,0],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,0],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：head = [[3,0],[3,0],[3,0]]
 * 输出：[[3,0],[3,0],[3,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 1000
 * -10^4 <= Node.val <= 10^4
 * Node.random 为 0 或指向链表中的节点。
 * 
 * 
 */

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = 0;
        random = 0;
    }

    Node(int val, Node *next, Node* random) {
        this->val = val;
        this->next = next;
        this->random = random;
    }
};

#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <cstddef>

using namespace std;

// @lc code=start
class Solution {
public:
    Node* copyRandomListOld(Node* head) {
        vector<Node*> srcVec;
        vector<Node*> dstVec;
        map<Node*, int> indexMap;
        Node ret(0), *pret = &ret;

        Node *tmp = head;
        int index = 0;
        while (tmp) {
            Node* node = tmp;
            tmp = tmp->next;
            indexMap[node] = index;
            srcVec.push_back(node);

            Node* newNode = new Node(node->val);
            pret->next = newNode;
            pret = pret->next;
            dstVec.push_back(newNode);
            index++;
        }
        pret->next = 0;

        for (int i = 0; i < dstVec.size(); i++) {
            Node* srcNode = srcVec[i];
            Node* dstNode = dstVec[i];
            if (srcNode->random) {
                int randomIndex = indexMap[srcNode->random];
                dstNode->random = dstVec[randomIndex];
            } else {
                dstNode->random = 0;
            }
        }

        return ret.next;
    }

    Node* copyRandomList(Node* head) {
        map<Node*, Node*> nodeMap;

        Node* cur = head;
        while (cur) {
            nodeMap[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            Node* newNode = nodeMap[cur];
            newNode->random = nodeMap[cur->random];
            newNode->next = nodeMap[cur->next];
            cur = cur->next;
        }

        return nodeMap[head];
    }
};
// @lc code=end

int main(void)
{
    Node *t0 = new Node(7);
    Node *t1 = new Node(13);
    Node *t2 = new Node(11);
    Node *t3 = new Node(10);
    Node *t4 = new Node(1);

    t0->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = 0;

    t0->random = 0;
    t1->random = t0;
    t2->random = t4;
    t3->random = t2;
    t4->random = t0;

    Solution s;

    s.copyRandomList(t1);
    return 0;
}