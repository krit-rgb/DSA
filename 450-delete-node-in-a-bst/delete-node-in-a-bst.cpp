class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // Handles empty tree or key not found

        // Traverse left or right to find the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found! Handle deletion cases:

            // 0 or 1 child (Right only)
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 1 child (Left only)
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 2 children: Find in-order successor
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }

            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};