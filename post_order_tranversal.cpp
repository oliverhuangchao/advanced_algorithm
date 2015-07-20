/*
    build a bst with its inorder and postorder tranversal

*/
#include "basic.h"


/*
post order tranversal
both in recurisve and iteratly
*/


void dfs(TreeNode* root,vector<int> &result){
    if(root == NULL)
        return;
    else{
        dfs(root->left,result);
        dfs(root->right,result);
        result.push_back(root->val);// put it in the end
    }
}

vector<int>  post_order(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> z;
    /*
        dfs(root,result);
    */
    /*
        ------ below is the iterative solution ------
    */
    TreeNode *p = root;
    TreeNode *q = NULL;;

    do{
        while(p){
            z.push(p);
            p = p->left;
        }
        q = NULL;// quite important 
        while(!z.empty()){
            p = z.top();
            z.pop();
            if(q == p->right){
                result.push_back(q->val);
                q = p;// make q equal to p
            }
            else{
                z.push(p);
                p = p->right;
                break;
            }
        }
    }while(!z.empty());
    return result;
}


int main(int argc, char* argv[]){
    //int n = atoi(argv[1]);
    string str(argv[1]);
    /*int x[] = {5,4,3,2,1};
    int len = sizeof(x)/sizeof(x[0]);*/
   
}