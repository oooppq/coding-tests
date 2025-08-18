/*
대충 비슷한 접근까진 갔는데,
뭔가 답답해서 걍 답 봤다.
sort 카테고리에 있어서 sorting 생각했는데,
그냥 dp문제였다.
나는 start를 무조건 sliding하면서 고려해야한다고 생각했는데,
애초에 시작지점에서 gas[i] - cost[i]가 음수일 수 없고,
start부터 i까지 어떤 지점을 start로 잡아도,
그지점부터 누적합을 구해도 음수일 수 밖에 없다.
다시 풀어볼만한 문제.
*/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if (totalGas < totalCost)
        {
            return -1;
        }

        int currentGas = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            currentGas += gas[i] - cost[i];
            if (currentGas < 0)
            {
                currentGas = 0;
                start = i + 1;
            }
        }

        return start;
    }
};