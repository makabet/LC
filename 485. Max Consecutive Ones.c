/*
https://leetcode.com/problems/max-consecutive-ones/

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/
#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
    if (numsSize < 1)   return 0;
    if (nums == NULL)   return 0;

    int maxLen = 0;
    int cnd = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            ++cnd;
            if (maxLen < cnd) {
                maxLen = cnd;
            }
        } else {
            cnd = 0;
        }
    }
    return maxLen;
}

/**********************************************/
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int start = -1, end = -1;
    int dis = 0;
    
    for(int i = 0; i<numsSize; i++){
        if(start==-1 && nums[i]==1){
            start = i;
            end = i;
        }
        else if(start!=-1 && nums[i]==1){
            end = i;
        }
        else if(nums[i]==0){
            start = -1;
        }
        
        if(start!=-1 && (end-start+1)>dis) dis = end-start+1;
    }
    
    return dis;
}

/**********************************************/
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    
    int maxcon = 0;
    int currentCon = 0;
    
    for (int i = 0 ; i < numsSize ; i++)
    {
        if (nums[i])
        {
            currentCon++;
            maxcon = (currentCon > maxcon) ? currentCon : maxcon;
        }
        else
        {
            currentCon = 0;
        }
    }
    
    return maxcon;
}

