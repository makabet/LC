/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include <stdio.h>

int search(int* nums, int numsSize, int target){
    if (nums == NULL) return -1;
    if (numsSize < 1) return -1;

    int i = 0;
    int max = numsSize - 1;
//    printf ("%d %d\n", nums[(numsSize - 1) / 2], target);
    if (i > 2) {
        if (nums[(numsSize - 1) / 2] > target) {
            i = (numsSize - 1) / 2;
            max = numsSize - 1;
        } else {
            max = (numsSize - 1) / 2;
        }
    }
//    printf ("serch %d %d\n", i, max);
    for (; i <= max; i++) {
//        printf("%d %d\n", i, nums[i]);
        if (target == nums[i]) {
            return i;
        }
    }
    return -1;
}
/***********************************************/
int search(int* nums, int numsSize, int target){
    for(int j=0; j<numsSize; j++)
        if(nums[j]==target) return j;
        else if(nums[numsSize-j-1]==target) return numsSize-j-1;
        else;
    return -1;
}

/***********************************************/
int findPivot(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    int mid;
    int start = nums[0];
    int pivot = -1;
    
    while (left <= right) {
        mid = (left + right)/2;
        if (nums[mid] < start) {
            if ((mid < 1) || (nums[mid - 1] >= start)) {
                pivot = mid;
                break;
            } else
                right = mid - 1;
        } else {
            left = mid + 1;
            
        }
        
    }
    
    return pivot;
    
}

int findTarget(int* nums, int left, int right, int target) {
    int mid;
    
    while(left <= right) {
        mid = (left + right)/2;
        
        if (nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}


int search(int* nums, int numsSize, int target) {
    int pivot = 0;
    int index; 
    
    pivot = findPivot(nums, numsSize);
    
    index = findTarget(nums, 0, pivot - 1, target);
    if (index == -1)
        index = findTarget(nums, pivot, numsSize - 1, target);
    
    return index;
}