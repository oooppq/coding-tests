/*
못품.
아이디어가 되게 중요하다.
설명에서 n개의 node, n-1개의 edge가 있다면
acyclic이라는 것을 알 수 있고, valid한 tree라는 설명이 있으니,
모든 node가 연결되어 있으면서 임의의 두 node를 연결하는 경로가 항상 하나만 존재한다는 것을 의미한다.
만약, a -> b까지 갈 때, path 중간에 낀 노드들이 있고, path의 모든 node들을 XOR 해주면,
a, b를 제외한 모든 node가 XOR연산 두 번을 먹게 돼서 다시 자기 자신이 되는 것을 알 수 있다.
즉, a와 b의 XOR 값만 고려하면 된다는 것..
그래서, 그냥 아무 두 node를 짝지어서 greedy하게 계산하면 된다.
이때, 풀이와 같이 오름차순 sort해주어서 XOR할 때 크게 증가하는 놈들끼리 짝지어주면 된다.
홀수일 때에는 마지막꺼를 그냥 버려주면 된다. 가장 작기 때문에, 얘랑 짝짓는거보다 앞에서 짝지어진 경우가 더 큰 값이기 때문.
*/

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k,
                              vector<vector<int>> &edges)
    {
        vector<int> netChange;
        long long nodeSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            netChange.push_back((nums[i] ^ k) - nums[i]);
            nodeSum += 1ll * nums[i];
        }

        // Sort netChange in decreasing order
        sort(netChange.begin(), netChange.end(), greater<int>());

        for (int i = 0; i < netChange.size(); i += 2)
        {
            // If netChange contains odd number of elements break the loop
            if (i + 1 == netChange.size())
            {
                break;
            }
            long long pairSum = netChange[i] + netChange[i + 1];

            // Include in nodeSum if pairSum is positive
            if (pairSum > 0)
            {
                nodeSum += pairSum;
            }
        }
        return nodeSum;
    }
};