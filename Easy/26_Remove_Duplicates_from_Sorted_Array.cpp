// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,2,2,3,3,4],

// Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

// It doesn't matter what values are set beyond the returned length.
// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

//没有考虑的问题：边界问题,空输入的情况
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            if(nums.size()<=1)
                return nums.size();
            int cur=0,i=0;
            while(i<nums.size()-1){
                if(nums[++i]==nums[cur])
                    continue;
                else
                    nums[++cur]=nums[i];
            }
            nums.erase(nums.begin()+cur+1,nums.end());
            return ++cur;
    }
};
int main(){
    Solution solu;
    vector<int> iv={0,0,1,1,1,2,2,3,3,4};
    cout<<solu.removeDuplicates(iv)<<endl;
    for(auto i:iv)
        cout<<i<<endl;
}