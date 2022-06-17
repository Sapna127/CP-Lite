// https://leetcode.com/problems/binary-tree-cameras/submissions/
// https://www.youtube.com/watch?v=qqMyB0fnphQ

//2 - means node has camera
//1 - node dont have cam but its monitored
//0 - neither have cam nor monitored
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int sum = 0;
        if(dfs(root,sum)==0) sum++; //if root isnt monitored we place additiomal camera
        return sum;
    }
    int dfs(TreeNode *rt,int &sum){
        if(!rt) return 1;
        int l=dfs(rt->left,sum) , r=dfs(rt->right,sum);
        if(!l || !r){
            sum++;
            return 2;
        }
        else if(l==2 || r==2) return 1;
        else return 0;
    }
  
  // TC O(n) n = num of nodes
  // SC O(h) h = height of binary tree
