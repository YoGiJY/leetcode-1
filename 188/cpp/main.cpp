#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    /**
     * 计算最大收益
     * @param k : 至多进行k次买卖
     * @param prices : 每日价格
     * @return : 最大收益 
     */
    int maxProfit(int k, vector<int>& prices) {
        int pricesSize = prices.size();

        /* 如果价格数据为空或只有一个数据，或者不能进行买卖，返回0  */
        if (pricesSize <= 1 || k <= 0) return 0;

        /* k>=pricesSize，相当于不限交易次数 */
        if (k >= pricesSize) {
            int max = 0;
            for (int i = 1; i < pricesSize; ++i)
                if (prices[i] > prices[i-1])
                    max += prices[i] - prices[i-1];
            return max;
        }

        // 第i次买入和卖出时的最大收益
        vector<int> buy(pricesSize + 1, numeric_limits<int>::min()), sell(pricesSize + 1); 
    
        for (int day = 0; day < pricesSize; ++day) {
            for (int transaction = 1; transaction <= k; ++transaction) {
                buy[transaction] = bigger(buy[transaction], sell[transaction - 1] - prices[day]);
                sell[transaction] = bigger(sell[transaction], buy[transaction] + prices[day]);
            }
        }

        return sell[k];
    }

private:
    int bigger(int a, int b) {
        return a > b ? a : b;
    }
};

void test(Solution s, int k, vector<int>& prices) {
    cout << "[";
    for (int i = 0, len = prices.size() - 1; i < len; ++i)
        cout << prices[i] << ",";
    cout << prices[prices.size() - 1] << "], " 
        << "k=" << k << " : " << s.maxProfit(k, prices) << endl;
}

int main(void) {
    Solution s;
    vector<int> prices;
    prices.push_back(5);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(0);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(1);
    test(s, 1, prices);
    test(s, 2, prices);
    test(s, 3, prices);
    test(s, 100, prices);
    return 0;
}
