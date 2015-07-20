/*
    build a bst with its inorder and postorder tranversal

*/
#include "basic.h"
void dfs(int left,int right,vector<string> &result,string &path,int N){
    if(left > N) return;
    if(right == N){
        result.push_back(path);
        return;
    }
    path.push_back('(');
    dfs(left+1,right,result,path,N);
    path.pop_back();
    if(left>right){
        path.push_back(')');
        dfs(left,right+1,result,path,N);
        path.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string path;
    dfs(0,0,result,path,n);
    print(result);
    return result;
}


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    /*int x[] = {5,4,3,2,1};
    int len = sizeof(x)/sizeof(x[0]);*/

    generateParenthesis(n);
   
}