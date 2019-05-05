/*
https://leetcode.com/problems/binary-search/

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4

Example 2:
    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1
 
Note:
    You may assume that all elements in nums are unique.
    n will be in the range [1, 10000].
    The value of each element in nums will be in the range [-9999, 9999].
*/
#include <stdio.h>

int search(int* nums, int numsSize, int target){
    if (nums == NULL) return -2;
    if (numsSize < 0) return -3;

    for (int i = 0; i < numsSize; i++) {
        if (*nums++ == target) return i;
    }
    return -1;
}

/***********************************************/
int search(int* nums, int numsSize, int target) {
    int l=0, r=numsSize-1, k=target;
    if (!nums) return -1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (k == nums[mid]) { return mid; }
        else if (k < nums[mid]) { r = mid - 1; }
        else { l = mid + 1; }
    }
    return -1;   
}

/***********************************************/
int search(int* nums, int numsSize, int target) {
    return searchRecursive(nums, 0, numsSize-1, target);
}

int searchRecursive(int* nums, int startIndex, int endIndex, int target) {
    if (startIndex <= endIndex) {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        
        // compare midElement with target
        if (nums[midIndex] == target) {
            // Found
            return midIndex;
        } else if (nums[midIndex] < target) {
            // midElement is too small - go right
            return searchRecursive(nums, midIndex+1, endIndex, target);
        } else {
            // midElement is too big - go left
            return searchRecursive(nums, startIndex, midIndex-1, target);
        }
        
    }
    
    // not found
    return -1;
}