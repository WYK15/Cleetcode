#include <iostream>
#include <string.h>

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

    int countSubstrings(string s) {
        int len = s.length();
        bool dp[len][len];
        int result = 0;
        memset(dp,0,len*len);
        for (int i = len-1; i >=0 ; i--) {
            for (int j = i; j < len; j++) {
                dp[i][j] = (s[i]==s[j]) && ( (j-i)<=2 || dp[i+1][j-1] );
                if (dp[i][j]) result++;
            }
        }
        return result;
    }
};


int main(){
    cout<<Solution().countSubstrings("aaaaa");
    return 0;
}
