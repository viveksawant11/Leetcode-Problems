#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Base cases
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        
        // Check original structure
        bool isSame = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        if (isSame) {
            return true;
        }
        
        // Check flipped structure
        return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }
};

TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->left->right->left = newNode(7);
    root1->left->right->right = newNode(8);

    TreeNode* root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->left = newNode(4);
    root2->right->right = newNode(5);
    root2->left->right = newNode(6);
    root2->right->right->left = newNode(8);
    root2->right->right->right = newNode(7);

    Solution solution;
    bool result = solution.flipEquiv(root1, root2);

    cout << (result ? "The trees are flip equivalent." : "The trees are not flip equivalent.") << endl;

    return 0;
}
