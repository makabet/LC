/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * 2);
    if (ret == NULL)
        return NULL;
    ret[0] = -1;
    ret[1] = -1;

    *returnSize = 2;

    if (nums == NULL)   return ret;
    if (numsSize < 1)  return ret;
    if (returnSize == NULL) return ret;

    int L = 0;
    int R = numsSize - 1;

    while (L < R) {
        int M = (L + R) / 2;
        if (nums[M] < target) {
            L = M + 1;
        } else {
            R = M;
        }
    }


    // get Start Position
    if (nums[R] == target) {
        ret[0] = R;
    } else if (nums[L] == target) {
        ret[0] = L;
    } else {
        return ret;
    }

    for (int i = ret[0]; i < numsSize; i++) {
//        printf ("%d %d\n", i, nums[i]);
        if (nums[i] == target) {
            ret[1] = i;
        } else {
            break;
        }
    }

//    printf("%d %d\n", ret[0], ret[1]);
    return ret;
}
