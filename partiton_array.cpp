/*
    build a bst with its inorder and postorder tranversal

*/
#include "basic.h"

inline int swap(vector<int> &nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
int partitionArray(vector<int> &nums, int k) {
    // write your code here
    int pivot = k;
    int a = 0;
    int b = nums.size()-1;
    while(a<b){
        while(a<b && nums[b]>=pivot )
        	b--;
        while(a<b && nums[a]<pivot)
        	a++;
        swap(nums,a,b);
    }
    //print(nums);
    a = 0;
    b = nums.size()-1;
    while(a<b){
        while(a<b && nums[b]>pivot )
        	b--;
        while(a<b && nums[a]<=pivot)
        	a++;
        swap(nums,a,b);
    }

    for(int i=0;i<nums.size();i++)
    	if(nums[i] == k) return i;
    //return a;
}


int main(int argc, char* argv[]){
    int x[] = {9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9};
    int len = sizeof(x)/sizeof(x[0]);
   	vector<int> nums = getVector(x,len);
   	print(nums);
   	print(partitionArray(nums,9));
   	print(nums);
}