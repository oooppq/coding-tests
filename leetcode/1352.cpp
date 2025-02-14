/*
구현 문젠데, 그냥 너무쉽다. 그때그때 곱하는것 보다 그냥 누적곱 구해놓는게 더 시간복잡도 줄이는 방법.
*/

class ProductOfNumbers
{
public:
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        nums.push_back(num);
    }

    int getProduct(int k)
    {
        int n = nums.size();
        int ret = 1;
        for (int i = n - k; i < n; i++)
            ret *= nums[i];

        return ret;
    }

private:
    vector<int> nums;
};
