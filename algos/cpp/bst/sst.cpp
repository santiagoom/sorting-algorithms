# include <iostream>
# include <vector>
# include <myutils.h>
//# include <myTreeNode.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:

    bool isBST(TreeNode *root) {

        vector<int> res;
        inorder(root, res);

        for (int i = 0; i < res.size - 1; i++) {
            if (res[i] > res[i + 1])
                return false;

        }
        return true;


    }

    void inorder(TreeNode *root, vector<int> &res) {
        if (!root)
            return;
        inorder(root->left)
        res.push_back(root->val);
        inorder(root->right);
    }

};

class Solution1 {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode *root, int low, int high) {
        if (root == NULL)
            return true;
        if (low < root->val && root->val < high)
            return (isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high));
        else
            return false;
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    delete so;
    return 0;
}
