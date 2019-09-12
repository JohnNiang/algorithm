#include <iostream>

using namespace std;

// Child and sibling representation of tree.

struct TreeNode {
    int data;
    TreeNode* firstChild;
    TreeNode* nextSibling;
};

/**
 * 求孩子兄弟表示法存储的森林的叶子节点。
 */
int countLeaf(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    if(root->firstChild == nullptr) {
        return 1 + countLeaf(root->nextSibling);
    }
    return countLeaf(root->firstChild) + countLeaf(root->nextSibling);
}

/**
 * 获取树的高度。
 */
int getHeight(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    } else {
        int firstChildHeight = 0;
        int nextSiblingHeight = 0;

        firstChildHeight = getHeight(root->firstChild);
        nextSiblingHeight = getHeight(root->nextSibling);

        if(firstChildHeight + 1 > nextSiblingHeight) {
            return firstChildHeight + 1;
        } else {
            return nextSiblingHeight;
        }
    }
}

int main() {

    return 0;
}
