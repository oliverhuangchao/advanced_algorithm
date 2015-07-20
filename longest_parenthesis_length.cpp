/*
    build a bst with its inorder and postorder tranversal

*/
#include "basic.h"


/*
longest valid parenthesis
also return the what is the longest substring is
*/

int longestValidParentheses(string str) {
    stack<int> z;
    int i=0;
    int res = 0; // key point is how to set the init of res
    int start = -1; //key point is how to set start position
    int max_len = 0;
    int max_start = 0;
    while(i<str.size()){
        if(str[i] == '('){
            z.push(i);
        }
        else{
            if(z.empty())  start = i;
            else{
                z.pop();
                if(z.empty()){
                    if(max_len < i-start){
                        max_len = i-start;
                        max_start = start+1;
                    }
                }
                //res = max(res,i-start);
                else{
                    if(max_len < i-start){
                        max_len = i-z.top();
                        max_start = z.top()+1;
                    }
                    //res = max(res,i-z.top());
                }
            }
        }
        i++;
    }
    print(str.substr(max_start,max_len));
    return max_len;
}
//dp solution
// dp could also solve this problem, but it is quite complex


int main(int argc, char* argv[]){
    //int n = atoi(argv[1]);
    string str(argv[1]);
    /*int x[] = {5,4,3,2,1};
    int len = sizeof(x)/sizeof(x[0]);*/

    print(longestValidParentheses(str));
   
}