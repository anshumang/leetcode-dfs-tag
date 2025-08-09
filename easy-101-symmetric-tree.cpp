#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
};

class SolutionIter {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* a = q.front(); q.pop();
            TreeNode* b = q.front(); q.pop();

            if (!a && !b) continue;
            if (!a || !b) return false;
            if (a->val != b->val) return false;

            // mirror pairing
            q.push(a->left);  q.push(b->right);
            q.push(a->right); q.push(b->left);
        }
        return true;
    }
};
