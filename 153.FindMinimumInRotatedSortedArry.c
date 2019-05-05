/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Suppose an array sorted in ascending order is rotated at some pivot
unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:
    Input: [3,4,5,1,2] 
    Output: 1

Example 2:
    Input: [4,5,6,7,0,1,2]
    Output: 0
*/
#include <stdio.h>

int findMin(int* nums, int numsSize){
    if (nums == NULL)   return -1;
    if (numsSize < 1)   return -1;

    int i;
    for (i = 1 ; i< numsSize ;i++)
        if (nums[i] < nums[i-1])
            return nums[i];
    
    return nums[0];
}

/***********************************************/
int findMin(int* nums, int numsSize){
    int min = 0x7FFFFFFF;
    for (int i = 0; i < numsSize; i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }
    return min;
}
