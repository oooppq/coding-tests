/*
쉬움요.
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        int prev = 10001;
        for (auto price : prices)
        {
            if (price < prev)
                prev = price;
            else
            {
                profit = max(profit, price - prev);
            }
        }

        return profit;
    }
};