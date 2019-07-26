#include <iostream>
#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
        int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
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

    //647
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

    //868
    int binaryGap(int N) {
        if (!N)
            return 0;
        int last = 0,result = 0;
        while (N != 0) {
            if ( N & 1 == 1) {
                N >>= 1;
                break;
            } else{
                last++;
            }
            N >>= 1;
        }
        int index = last+1;
        while (N != 0) {
            if (N & 1 == 1) {
                result = max(result,index - last);
                last = index;
            }
            index++;
            N >>= 1;
        }
        return result;
    }

    //147对链表进行插入排序
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode *sortlast = head;
        ListNode *tmp ,*first = head;
        while(tmp = sortlast->next) {
            if (tmp->val >= sortlast->val){
                sortlast = tmp;
                continue;
            }
            if (tmp->val <= first->val) {
                sortlast->next = tmp->next;
                tmp->next = first;
                first = tmp;
                continue;
            }
            ListNode *iter = first;
            while (iter != sortlast) {
                if (tmp->val >= iter->val && tmp->val < iter->next->val){
                    sortlast->next = tmp->next;
                    tmp->next = iter->next;
                    iter->next = tmp;
                    break;
                }
                iter = iter->next;
            }
        }
        return first;
    }


};


int main(){
    cout<<Solution().binaryGap(5);
    return 0;
}
