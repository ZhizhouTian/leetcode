/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印 FooBar
 *
 * https://leetcode.cn/problems/print-foobar-alternately/description/
 *
 * concurrency
 * Medium (57.02%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    65.2K
 * Total Submissions: 114.3K
 * Testcase Example:  '1'
 *
 * 给你一个类：
 * 
 * 
 * class FooBar {
 * ⁠ public void foo() {
 * for (int i = 0; i < n; i++) {
 * print("foo");
 * }
 * ⁠ }
 * 
 * ⁠ public void bar() {
 * for (int i = 0; i < n; i++) {
 * print("bar");
 * }
 * ⁠ }
 * }
 * 
 * 
 * 两个不同的线程将会共用一个 FooBar 实例：
 * 
 * 
 * 线程 A 将会调用 foo() 方法，而
 * 线程 B 将会调用 bar() 方法
 * 
 * 
 * 请设计修改程序，以确保 "foobar" 被输出 n 次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 1
 * 输出："foobar"
 * 解释：这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 2
 * 输出："foobarfoobar"
 * 解释："foobar" 将被输出两次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 1000
 * 
 * 
 */

#include <pthread.h>

using namespace std;

// @lc code=start
class FooBar {
private:
    int n;
    pthread_mutex_t mtx1, mtx2;

public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_init(&mtx1, NULL);
        pthread_mutex_init(&mtx2, NULL);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mtx1);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            pthread_mutex_unlock(&mtx2);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mtx2);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            pthread_mutex_unlock(&mtx1);
        }
    }
};
// @lc code=end

