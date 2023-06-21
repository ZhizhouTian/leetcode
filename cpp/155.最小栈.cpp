/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode.cn/problems/min-stack/description/
 *
 * algorithms
 * Medium (58.98%)
 * Likes:    1593
 * Dislikes: 0
 * Total Accepted:    484.4K
 * Total Submissions: 821.1K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 实现 MinStack 类:
 * 
 * 
 * MinStack() 初始化堆栈对象。
 * void push(int val) 将元素val推入堆栈。
 * void pop() 删除堆栈顶部的元素。
 * int top() 获取堆栈顶部的元素。
 * int getMin() 获取堆栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 <= val <= 2^31 - 1
 * pop、top 和 getMin 操作总是在 非空栈 上调用
 * push, pop, top, and getMin最多被调用 3 * 10^4 次
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
#if 0
class DLinkNode {
public:
    int value;
    DLinkNode *prev, *next;

    DLinkNode(int value) {
        this->value = value;
        this->prev = this->next = this;
    }
};

class MinStack {
private:
    vector<DLinkNode*> stack;
    int count;
    DLinkNode *head;

    void insertMin(DLinkNode *node) {
        DLinkNode *tmp = this->head->next, *last = this->head;
        for (; tmp != this->head; tmp = tmp->next) {
            if (last->value <= node->value && node->value <= tmp->value)
                break;
            last = tmp;
        }

        node->next = last->next;
        node->prev = last;
        last->next->prev = node;
        last->next = node;
    }

    void remove(DLinkNode *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = node->next = node;
    }

public:
    MinStack() {
        this->count = 0;
        this->head = new DLinkNode(INT32_MIN);
    }

    ~MinStack() {
        delete this->head;
    }

    void push(int val) {
        DLinkNode *node = new DLinkNode(val);
        insertMin(node);
        this->stack.push_back(node);
    }
 
    void pop() {
        if (this->stack.empty())
            return;
        DLinkNode *top = this->stack[this->stack.size() - 1];
        this->stack.pop_back();
        remove(top);
        delete top;
    }
    
    int top() {
        if (this->stack.empty())
            return 0;
        return this->stack[this->stack.size() - 1]->value;
    }
    
    int getMin() {
        if (this->stack.empty())
            return 0;
        return this->head->next->value;
    }
};
#endif

#include <stack>

class MinStack {
    stack<int> numStack;
    stack<int> minStack;

public:
    MinStack() {
        minStack.push(INT32_MAX);
    }

    void push(int val) {
        numStack.push(val);

        minStack.push(min(minStack.top(), val));
    }
 
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main(void)
{
    MinStack *obj = new MinStack();
    obj->push(3);
    obj->push(1);
    obj->push(2);
    obj->pop();
    cout << "min: " << obj->getMin() << endl;
    cout << "top: " << obj->top() << endl;
}