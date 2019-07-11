#include <iostream>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    // 100 simple
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q ) return true;
        if(!(p && q)) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main(){
    cout<<"hello world"<<endl;
    return 0;
}
