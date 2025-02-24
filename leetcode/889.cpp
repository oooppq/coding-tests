/*
진짜 생각해보지도 못한 유형의 생각해보지도 못한 풀이다.
divide and conquer로 푸는 문젠데, 현재 scope의 preorder 배열의 첫 번째는 root고,
그 다음 element는 무조건 left child인 점과, postorder에서 이 left child 앞에 있는 놈들은 모두 left child의 subtree라는 점이 key다.
이를 통해, 각 subtree의 개수를 알 수 있게 되고, 다음 recursion에서는 subtree에 해당하는 부분만 탐색할 수 있는 것이다.

꼭 꼮 다시풀자
*/

class Solution
{
    int i = 0;

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();

        return recur(0, n - 1, 0, preorder, postorder);
    }

    TreeNode *recur(int preStart, int preEnd, int postStart, vector<int> &preorder, vector<int> &postorder)
    {
        if (preStart > preEnd)
            return NULL;

        if (preStart == preEnd)
            return new TreeNode(preorder[preStart]);

        int left = preorder[preStart + 1];

        int treeCount = 1;
        while (left != postorder[postStart + treeCount - 1])
            treeCount++;

        TreeNode *root = new TreeNode(preorder[preStart]);

        root->left = recur(preStart + 1, preStart + treeCount, postStart, preorder, postorder);
        root->right = recur(preStart + treeCount + 1, preEnd, postStart + treeCount, preorder, postorder);

        return root;
    }
};