/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 *
 * https://leetcode.cn/problems/print-in-order/description/
 *
 * concurrency
 * Easy (65.16%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    111.9K
 * Total Submissions: 171.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个类：
 * 
 * 
 * public class Foo {
 * public void first() { print("first"); }
 * public void second() { print("second"); }
 * public void third() { print("third"); }
 * }
 * 
 * 三个不同的线程 A、B、C 将会共用一个 Foo 实例。
 * 
 * 
 * 线程 A 将会调用 first() 方法
 * 线程 B 将会调用 second() 方法
 * 线程 C 将会调用 third() 方法
 * 
 * 
 * 请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。
 * 
 * 提示：
 * 
 * 
 * 尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
 * 你看到的输入格式主要是为了确保测试的全面性。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出："firstsecondthird"
 * 解释：
 * 有三个线程会被异步启动。输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C
 * 将会调用 third() 方法。正确的输出是 "firstsecondthird"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,3,2]
 * 输出："firstsecondthird"
 * 解释：
 * 输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second()
 * 方法。正确的输出是 "firstsecondthird"。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums 是 [1, 2, 3] 的一组排列
 * 
 * 
 */
#include <pthread.h>

// @lc code=start
class Foo {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int seq;

public:
    Foo() {
        pthread_mutex_init(&mutex, NULL);
        pthread_cond_init(&cond, NULL);
        seq = 0;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        seq = 1;
        pthread_cond_broadcast(&cond);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&mutex);
        while (seq != 1)
            pthread_cond_wait(&cond, &mutex);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        seq = 2;
        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&mutex);
        while (seq != 2)
            pthread_cond_wait(&cond, &mutex);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        pthread_mutex_unlock(&mutex);
    }
};
// @lc code=end

