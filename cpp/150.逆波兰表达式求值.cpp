/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (52.68%)
 * Likes:    755
 * Dislikes: 0
 * Total Accepted:    283.1K
 * Total Submissions: 537.5K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
 * 
 * 请你计算该表达式。返回一个表示表达式值的整数。
 * 
 * 注意：
 * 
 * 
 * 有效的算符为 '+'、'-'、'*' 和 '/' 。
 * 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
 * 两个整数之间的除法总是 向零截断 。
 * 表达式中不含除零运算。
 * 输入是一个根据逆波兰表示法表示的算术表达式。
 * 答案及所有中间计算结果可以用 32 位 整数表示。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：tokens = ["2","1","+","3","*"]
 * 输出：9
 * 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：tokens = ["4","13","5","/","+"]
 * 输出：6
 * 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * 输出：22
 * 解释：该算式转化为常见的中缀算术表达式为：
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= tokens.length <= 10^4
 * tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），或是在范围 [-200, 200] 内的一个整数
 * 
 * 
 * 
 * 
 * 逆波兰表达式：
 * 
 * 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
 * 
 * 
 * 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
 * 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
 * 
 * 
 * 逆波兰表达式主要有以下两个优点：
 * 
 * 
 * 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
 * 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
 * 
 * 
 */

#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
    bool isOperator(string& token) {
        if (token.size() != 1) return false;
        char c = token[0];
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int calculate(char opt, int n1, int n2) {
        switch (opt) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        }
        return 0; 
    }

public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> tokenStack;

        for (auto& t: tokens) {
            if (isOperator(t)) {
                if (tokenStack.size() < 2) return 0;
                int n1 = tokenStack.top();
                tokenStack.pop();
                int n2 = tokenStack.top();
                tokenStack.pop();
                int result = calculate(t[0], n2, n1);
                tokenStack.push(result);
                continue;
            }
            tokenStack.push(stoi(t));
        }
        if (tokenStack.size() != 1) return 0;
        return tokenStack.top();
    }
};
// @lc code=end

int main(void) {
    vector<string> tokens = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
    Solution s;
    cout << s.evalRPN(tokens) << endl;
    return 0;
}
