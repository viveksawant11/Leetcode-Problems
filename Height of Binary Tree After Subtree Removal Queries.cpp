#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;
        traverseRightToLeft(root, 0);

        int queryCount = queries.size();
        vector<int> queryResults(queryCount);
        for (int i = 0; i < queryCount; i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:
    // Left to right traversal
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        // Store the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        currentMaxHeight = max(currentMaxHeight, currentHeight);        // Update the current maximum height

        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    // Right to left traversal
    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (node == nullptr) return;

        // Update the maximum height if this node were removed
        maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        currentMaxHeight = max(currentHeight, currentMaxHeight);        // Update the current maximum height

        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};

// Function to create a binary tree from a vector of integers.
TreeNode* createTree(const vector<int>& nodes, int index = 0) {
    if (index >= nodes.size() || nodes[index] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[index]);
    root->left = createTree(nodes, 2 * index + 1);
    root->right = createTree(nodes, 2 * index + 2);
    return root;
}

int main() {
    vector<int> treeNodes = {5, 8, 9, 2, 1, 3, 7, 4, 6};  
    vector<int> queries = {3, 2, 4, 8};

    TreeNode* root = createTree(treeNodes);

    Solution solution;
    vector<int> result = solution.treeQueries(root, queries);

    for (int height : result) {
        cout << height << " ";
    }
    cout << endl;

    return 0;
}
