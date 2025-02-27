/*
쉬운 문제. 그냥 트리 방문하면 된다.
문제 이해 자체가 조금 오래 걸려서 그르치..
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements
{
    unordered_set<int> us;
    int i = 0;

public:
    FindElements(TreeNode *root)
    {
        recur(root, 0);
    }

    bool find(int target)
    {
        return us.count(target) != 0;
    }

    void recur(TreeNode *root, int num)
    {
        root->val = num;
        // cout << num << endl;
        us.insert(num);
        if (root->left)
            recur(root->left, num * 2 + 1);
        if (root->right)
            recur(root->right, num * 2 + 2);
    }
};
