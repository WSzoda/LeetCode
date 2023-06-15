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
class Solution {
public:
    unordered_map<int, int> map; //level - value

    int maxLevelSum(TreeNode* root) {
        checkValue(root, 1);

        auto min = min_element(map.begin(), map.end(), [](const auto& l, const auto& r){return l.second >= r.second;});
        return min->first;
    }

    void checkValue(TreeNode *root, int level) {
        map[level] += root->val;
        if(root->left){
            checkValue(root->left, level+1);
        }
        if(root->right){
            checkValue(root->right, level+1);
        }
    }
};