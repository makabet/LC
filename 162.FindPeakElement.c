/*
https://leetcode.com/problems/find-peak-element/
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.

Example 1:
    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
    Input: nums = [1,2,1,3,5,6,4]
    Output: 1 or 5 
    Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.

Note:
    Your solution should be in logarithmic complexity.
*/
#include <stdio.h>

int findPeakElement(int* nums, int numsSize){
    if (nums == NULL) return -1;
    if (numsSize < 0) return -1;

    int ind = 0;
    int max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (max < nums[i]) {
            ind = i;
            max = nums[i];
        } else if (nums[i] < max && ind == i -1) {
            return i - 1;
        }
    }

    return ind;
}

/***********************************************/

int findPeakElement(int* nums, int numsSize){
    int i=0;
    int pre_val = nums[0];
    
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]>pre_val)
        {
            pre_val=nums[i];
        }
        else
        {
            return i-1;
        }
    }
    
    return numsSize-1;
}
