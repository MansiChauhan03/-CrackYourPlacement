class BSTIterator {
private:
    stack<TreeNode*> stk;
    void pushAll(TreeNode* root){
        while (root){
            stk.push(root);
            root= root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node= stk.top();
        stk.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return (!stk.empty());
    }
};
