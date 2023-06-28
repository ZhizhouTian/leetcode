#include <iostream>
#include <vector>

/*
 * see: https://leetcode.cn/leetbook/read/illustration-of-algorithm/m5zfc1/
 */

// 蛋糕最高售价

using namespace std;

class Solution {
public:
    // recursive method
    int maxCakePrice1(int n, vector<int> priceList) {
        if (n <= 1) return priceList[n];
        int maxPrice = 0;

        for (int i=0; i<n; i++) {
            maxPrice = max(maxPrice, maxCakePrice1(i, priceList) + priceList[n-i]);
        }

        return maxPrice;
    }

    // dynamic programming
    int maxCakePrice2(int n, vector<int> priceList) {
        vector<int> maxPrices(n + 2, 0);
        vector<int> cut(n + 2, 0);
        maxPrices[0] = 0;
        maxPrices[1] = 2;

        for (int i=2; i<=n; i++) {
            for (int j=1; i>=j && j<priceList.size(); j++) {
                if (maxPrices[i-j] + priceList[j] > maxPrices[i]) {
                    maxPrices[i] = maxPrices[i-j] + priceList[j];
                    cut[i] = j;
                }
            }
        }

        for (int i=1; i<=n; i++)
            cout << "i: " << i << ", cut: " << cut[i] << ", max:" << maxPrices[i] << endl;
        return maxPrices[n];
    }
};

int main(void)
{
    Solution s;
    vector<int> priceList = {0, 2, 3, 6, 7, 11, 15};
    cout << s.maxCakePrice2(6, priceList) << endl;
}