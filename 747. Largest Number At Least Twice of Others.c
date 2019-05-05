/*
https://leetcode.com/problems/largest-number-at-least-twice-of-others/

In a given integer array nums, there is always exactly one largest element.
Find whether the largest element in the array is at least twice as much as every other number in the array.
If it is, return the index of the largest element, otherwise return -1.

Example 1:
    Input: nums = [3, 6, 1, 0]
    Output: 1
    Explanation: 6 is the largest integer, and for every other number in the array x,
    6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 

Example 2:
    Input: nums = [1, 2, 3, 4]
    Output: -1
    Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 

Note:
    nums will have a length in the range [1, 50].
    Every nums[i] will be an integer in the range [0, 99].
*/
#include <stdio.h>

int dominantIndex(int* nums, int numsSize){
    if (nums == NULL)   return -1;
    if (numsSize <= 0)   return -1;

    int max = 0;
    int index = 0;
    int* val = nums;
    for (int i = 0; i < numsSize; i++, val++) {
        if (*val > max) {
            max = *val;
            index = i;
        }
    }

    val = nums;
    for (int i = 0; i < numsSize; i++, val++) {
        if (i == index)
            continue;

        if (*val != max && *val * 2 > max) {
            return -1;            
        }
//        printf ("%d %d\n", i, *val);
    }

    return index;
}

/***********************************************/
int dominantIndex(int* nums, int numsSize) {
    
       int max = -1, index = -1, second = -1;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] > max) {
                second = max;
                max = nums[i];
                index = i;
            } else if (nums[i] > second)
                second = nums[i];
        }
        return second * 2 <= max ? index : -1;
}

/***********************************************/
int dominantIndex(int* nums, int numsSize){
    
    int ret = -1;
    int max = 0;
    int secondMax = 0;
    int maxIndex = 0;
    int i;
    
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > max)
        {
            secondMax = max;
            max = nums[i];
            maxIndex = i;
        }
        else if (nums[i] > secondMax)
        {
            secondMax = nums[i];
        }
    }
    
    if (max >= 2*secondMax)
    {
        ret = maxIndex;
    }
    
    return ret;
}