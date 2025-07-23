/*
쉬움.
그냥 아래와같이 해도 됨
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i - 1] < prices[i])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int tmp = 0;
        for (int i = 1; i < prices.size(); i++)
        {

            if (prices[i - 1] <= prices[i])
            {
                tmp += prices[i] - prices[i - 1];
            }
            else
            {
                profit += tmp;
                tmp = 0;
            }
        }
        profit += tmp;

        return profit;
    }
};